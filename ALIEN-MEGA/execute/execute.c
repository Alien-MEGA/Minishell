/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:44:28 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/18 23:14:52 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_fd(int fd_in, int fd_out, int flag)
{
	if (flag == C_X)
	{
		ft_error(close(fd_in), 1);
		ft_error(close(fd_out), 1);
	}	
	else if (flag == C_IN)
		ft_error(close(fd_in), 1);
	else if (flag == C_OUT)
		ft_error(close(fd_out), 1);
}

void	run_redirect(t_list *redirect)
{
	int	fd_in;
	int	fd_out;

	fd_in = -2;
	fd_out = -2;
	if (!redirect)
		return ;
	while (redirect)
	{
		if (redirect->type == TK_RD_OUTPUT)
			fd_out = open(redirect->next->value, O_RDWR | O_TRUNC | O_CREAT, 0644);
		else if (redirect->type == TK_RD_OUTPUT_APPEND)
			fd_out = open(redirect->next->value, O_RDWR | O_APPEND | O_CREAT, 0644);
		ft_error(fd_out, 1);
		if (redirect->type == TK_RD_INPUT)
			fd_in = open(redirect->next->value, O_RDONLY);
		else if (redirect->type == TK_HERE_DOC)
			fd_in = open(here_doc(redirect->next->value), O_RDONLY);
		ft_error(fd_in, 1);
		redirect = redirect->next->next;
	}
	if (fd_in != -2)
		ft_error(dup2(fd_in, STDIN_FILENO), 1);
	if (fd_out != -2)
		ft_error(dup2(fd_out, STDOUT_FILENO), 1);
	ft_error(close(fd_in), 1);
	ft_error(close(fd_out), 1);
}

void	run_command(t_list *lst)
{
	char	*cmd;

	cmd = NULL;
	while (lst)
	{
		cmd = ft_strjoin_gnl(cmd, lst->value);
		lst = lst->next;
	}
	execute_x(cmd, g_pub.env);
}

t_fd	create_pipe(void)
{
	int 	fd[2];
	t_fd	fd_pipe;

	ft_error(pipe(fd), 1);
	fd_pipe.fd_rd = fd[0];
	fd_pipe.fd_wr = fd[1];
	return (fd_pipe);	
}

pid_t	run_x(t_tree *root, int fd_in, int fd_out, t_flag flags)
{
	pid_t	pross;

	pross = fork();
	ft_error(pross, 1);
	if (pross == 0)
	{
		ft_error(dup2(fd_in, STDIN_FILENO), 1);
		ft_error(dup2(fd_out, STDOUT_FILENO), 1);
		close_fd(fd_in, fd_out, flags.flag);
		run_redirect(root->redirect_mode);
		run_command(root->lst);
	}
	close_fd(fd_in, fd_out, flags.flag);
	if (flags.should_wait)
		g_pub.exit_status = wait_pross(pross);
	return (pross);
}

pid_t	execute(t_tree *root, int fd_in, int fd_out, t_flag flags)
{
	t_fd			fd_pipe;
	pid_t			pross;

	if (root->lst->type == TK_OR || root->lst->type == TK_AND)
	{
		execute(root->left, fd_in, fd_out, (t_flag) { .should_wait = TRUE, .flag = -1});
		if ((root->lst->type == TK_OR && g_pub.exit_status != 0)
			|| (root->lst->type == TK_AND && g_pub.exit_status == 0))
			execute(root->right, fd_in, fd_out, (t_flag) { .should_wait = TRUE, .flag = -1});
	}
	else if (root->lst->type == TK_PIPE)
	{
		fd_pipe = create_pipe();
		execute(root->left, fd_in, fd_pipe.fd_wr, (t_flag) { .should_wait = FALSE, .flag = C_OUT});
		pross = execute(root->right, fd_pipe.fd_rd, fd_out, (t_flag) { .should_wait = FALSE, .flag = C_IN});
		if (flags.should_wait == TRUE)
			g_pub.exit_status = wait_pross(pross);
	}
	else
		pross = run_x(root, fd_in, fd_out, flags);
	return (pross);
}

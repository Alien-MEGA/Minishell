/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:44:28 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/20 04:24:59 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_fd(int fd_in, int fd_out, int flag)
{
	if (flag == C_X)
	{
		if (isatty(fd_in) == 0)
			close(fd_in);
		if (isatty(fd_out) == 0)
			close(fd_out);
	}	
	else if (flag == C_IN)
		close(fd_in);
	else if (flag == C_OUT)
		close(fd_out);
}

t_fd	run_redirect(t_list *redirect)
{
	t_fd	fd_rd;

	fd_rd.fd_rd = -2;
	fd_rd.fd_wr = -2;
	if (!redirect)
		return (fd_rd);
	while (redirect)
	{
		if (redirect->type == TK_RD_OUTPUT)
			fd_rd.fd_wr = open(redirect->next->value, O_RDWR | O_TRUNC | O_CREAT, 0644);
		else if (redirect->type == TK_RD_OUTPUT_APPEND)
			fd_rd.fd_wr = open(redirect->next->value, O_RDWR | O_APPEND | O_CREAT, 0644);
		ft_error(fd_rd.fd_wr, 1);
		if (redirect->type == TK_RD_INPUT)
			fd_rd.fd_rd = open(redirect->next->value, O_RDONLY);
		else if (redirect->type == TK_HERE_DOC)
			fd_rd.fd_rd = open(here_doc(redirect->next->value), O_RDONLY);
		ft_error(fd_rd.fd_rd, 1);
		redirect = redirect->next->next;
	}
	return (fd_rd);
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
	t_fd			fd_red;
	pid_t			pross;

	if (!root || !root->lst)
		return (-1);
	if (root->lst->type == TK_OR || root->lst->type == TK_AND)
	{
		execute(root->left, fd_in, fd_out, (t_flag) { .should_wait = TRUE, .flag = -1});
		if (!(root->lst->type == TK_OR && g_pub.exit_status == 0))
			execute(root->right, fd_in, fd_out, (t_flag) { .should_wait = TRUE, .flag = -1});
	}
	else if (root->lst->type == TK_PIPE)
	{
		fd_pipe = create_pipe();
		execute(root->left, fd_in, fd_pipe.fd_wr, (t_flag) { .should_wait = FALSE, .flag = C_X});
		pross = execute(root->right, fd_pipe.fd_rd, fd_out, (t_flag) { .should_wait = FALSE, .flag = C_X});
		if (flags.should_wait == TRUE)
			g_pub.exit_status = wait_pross(pross);
	}
	else
	{
		fd_red = run_redirect(root->redirect_mode);
		if (fd_red.fd_rd < 0)
			fd_red.fd_rd = fd_in;
		if (fd_red.fd_wr < 0)
			fd_red.fd_wr = fd_out;
		pross = run_x(root, fd_red.fd_rd, fd_red.fd_wr, flags);
	}
	return (pross);
}

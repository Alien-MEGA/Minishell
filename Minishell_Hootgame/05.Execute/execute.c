/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:44:28 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/30 14:55:47 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

void	dup_fd(int fd_in, int fd_out)
{
	if (fd_in < 0 && fd_out < 0)
		return ;
	ft_error(dup2(fd_in, STDIN_FILENO), 1);
	ft_error(dup2(fd_out, STDOUT_FILENO), 1);
	close_fd(fd_in, fd_out);
}

void	close_fd(int fd_in, int fd_out)
{
	if (isatty(fd_in) == 0)
		close(fd_in);
	if (isatty(fd_out) == 0)
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
			fd_rd.fd_wr = open(redirect->next->value,
					O_RDWR | O_TRUNC | O_CREAT, 0644);
		else if (redirect->type == TK_RD_OUTPUT_APPEND)
			fd_rd.fd_wr = open(redirect->next->value,
					O_RDWR | O_APPEND | O_CREAT, 0644);
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

char	**get_cmd(t_list *lst)
{
	char	**cmd;
	int		i;

	i = 0;
	cmd = (char **)malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	while (lst)
	{
		if (lst->type != TK_WT_SPACE)
			cmd[i++] = ft_strdup(lst->value);
		lst = lst->next;
	}
	cmd[i] = NULL;
	return (cmd);
}

t_fd	create_pipe(void)
{
	int		fd[2];
	t_fd	fd_pipe;

	ft_error(pipe(fd), 1);
	fd_pipe.fd_rd = fd[0];
	fd_pipe.fd_wr = fd[1];
	return (fd_pipe);
}

pid_t	run_x(t_tree *root, int fd_in, int fd_out, int should_wait)
{
	pid_t	pross;
	char	**cmd;

	if (!root->lst)
		return (-1);
	cmd = get_cmd(root->lst);
	if (g_pub.should_fork != TRUE)
		if (run_builtin(cmd, fd_in, fd_out) == SUCCESS)
			return (-1);
	pross = fork();
	ft_error(pross, 1);
	if (pross == 0)
	{
		dup_fd(fd_in, fd_out);
		execute_x(cmd, g_pub.env);
	}
	close_fd(fd_in, fd_out);
	if (should_wait)
		g_pub.exit_status = wait_pross(pross);
	return (pross);
}

pid_t	execute(t_tree *root, int fd_in, int fd_out, int should_wait)
{
	t_fd			fd_pipe;
	t_fd			fd_red;
	pid_t			pross;

	if (!root)
		return (-1);
	pross = -1;
	if (root->lst && (root->lst->type == TK_OR || root->lst->type == TK_AND))
	{
		g_pub.should_fork = FALSE;
		execute(root->left, fd_in, fd_out, TRUE);
		g_pub.should_fork = FALSE;
		if ((root->lst->type == TK_OR && g_pub.exit_status != 0)
			|| (root->lst->type == TK_AND && g_pub.exit_status == 0))
			execute(root->right, fd_in, fd_out, TRUE);
	}
	else if (root->lst && root->lst->type == TK_PIPE)
	{
		fd_pipe = create_pipe();
		g_pub.should_fork = TRUE;
		execute(root->left, fd_in, fd_pipe.fd_wr, FALSE);
		g_pub.should_fork = TRUE;
		pross = execute(root->right, fd_pipe.fd_rd, fd_out, FALSE);
		if (should_wait == TRUE)
			g_pub.exit_status = wait_pross(pross);
	}
	else
	{
		if (expander(root) == FALSE)
			return (-1);
		fd_red = run_redirect(root->redirect_mode);
		if (fd_red.fd_rd < 0)
			fd_red.fd_rd = fd_in;
		if (fd_red.fd_wr < 0)
			fd_red.fd_wr = fd_out;
		pross = run_x(root, fd_red.fd_rd, fd_red.fd_wr, should_wait);
	}
	return (pross);
}

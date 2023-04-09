/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:44:28 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:13 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static t_fd	create_pipe(void)
{
	int		fd[2];
	int		*fd_in;
	t_fd	fd_pipe;

	ft_error(pipe(fd), 1);
	fd_pipe.fd_rd = fd[0];
	fd_pipe.fd_wr = fd[1];
	fd_in = (int *)malloc(sizeof(int));
	*fd_in = fd[0];
	ft_lstadd_back(&g_pub.fd_lst, ft_lstnew(-1, NULL, fd_in));
	fd_in = (int *)malloc(sizeof(int));
	*fd_in = fd[1];
	ft_lstadd_back(&g_pub.fd_lst, ft_lstnew(-1, NULL, fd_in));
	return (fd_pipe);
}

static pid_t	exec_cmd(t_tree *root, int fd_in, int fd_out, int should_wait)
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
		sig_inint(TP_SIG_CHILD);
		dup_fd(fd_in, fd_out);
		close_pipe_fd();
		execute_x(cmd, g_pub.env);
	}
	if (should_wait)
		g_pub.exit_status = wait_pross(pross);
	return (pross);
}

static void	exec_and_or(t_tree *root, int fd_in, int fd_out, int should_wait)
{
	g_pub.should_fork = FALSE;
	execute(root->left, fd_in, fd_out, TRUE);
	g_pub.should_fork = FALSE;
	if ((root->lst->type == TK_OR && g_pub.exit_status != 0)
		|| (root->lst->type == TK_AND && g_pub.exit_status == 0))
		execute(root->right, fd_in, fd_out, should_wait);
}

static void	exec_pipe(t_tree *root, int fd_in, int fd_out, int should_wait)
{
	t_fd	fd_pipe;
	pid_t	pross;

	fd_pipe = create_pipe();
	g_pub.should_fork = TRUE;
	execute(root->left, fd_in, fd_pipe.fd_wr, FALSE);
	close(fd_pipe.fd_wr);
	g_pub.should_fork = TRUE;
	pross = execute(root->right, fd_pipe.fd_rd, fd_out, FALSE);
	close(fd_pipe.fd_rd);
	if (should_wait == TRUE)
		g_pub.exit_status = wait_pross(pross);
}

pid_t	execute(t_tree *root, int fd_in, int fd_out, int should_wait)
{
	t_fd	fd_red;
	pid_t	pross;

	if (!root)
		return (-2);
	pross = -2;
	if (root->lst && (root->lst->type == TK_OR || root->lst->type == TK_AND))
		exec_and_or(root, fd_in, fd_out, should_wait);
	else if (root->lst && root->lst->type == TK_PIPE)
		exec_pipe(root, fd_in, fd_out, should_wait);
	else
	{
		if (expander(root) == FALSE)
			return (-1);
		fd_red = run_redirect(root->redirect_mode,
				(t_fd){.fd_rd = -2, .fd_wr = -2});
		if (fd_red.fd_rd < 0)
			fd_red.fd_rd = fd_in;
		if (fd_red.fd_wr < 0)
			fd_red.fd_wr = fd_out;
		pross = exec_cmd(root, fd_red.fd_rd, fd_red.fd_wr, should_wait);
	}
	return (pross);
}

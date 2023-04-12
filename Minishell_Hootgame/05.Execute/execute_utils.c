/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:23:26 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/12 04:51:21 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static int	handle_sig(int status)
{
	if (WTERMSIG(status) == SIGSTOP)
		ft_printf(2, "Minishell: SIG: Sendable stop signal not from tty\n");
	if (WTERMSIG(status) == SIGINT)
		ft_printf(2, "Minishell: SIG: Interrupt\n");
	if (WTERMSIG(status) == SIGQUIT)
		ft_printf(2, "Minishell: SIG: Quit\n");
	if (WTERMSIG(status) == SIGABRT)
		ft_printf(2, "Minishell: SIG: Abort\n");
	if (WTERMSIG(status) == SIGFPE)
		ft_printf(2, "Minishell: SIG: Floating point exception \n");
	if (WTERMSIG(status) == SIGKILL)
		ft_printf(2, "Minishell: SIG: Kill (cannot be caught or ignored)\n");
	if (WTERMSIG(status) == SIGBUS)
		ft_printf(2, "Minishell: SIG: Bus error\n");
	if (WTERMSIG(status) == SIGSEGV)
		ft_printf(2, "Minishell: SIG: Segmentation violation \n");
	if (WTERMSIG(status) == SIGSYS)
		ft_printf(2, "Minishell: SIG: Bad argument to system call\n");
	if (WTERMSIG(status) == SIGPIPE)
		ft_printf(2, "Minishell: SIG: Write on a pipe with no one to read it\n");
	if (WTERMSIG(status) == SIGTERM)
		ft_printf(2, "Minishell: SIG: Software termination signal from kill\n");
	if (WTERMSIG(status) == SIGCHLD)
		ft_printf(2, "Minishell: SIG: To parent on child stop or exit\n");
	return (128 + WTERMSIG(status));
}

static int	get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (handle_sig(status));
	return (0);
}

void	close_pipe_fd(void)
{
	t_list	*fd_lst;
	int		*fd;

	fd_lst = g_pub.fd_lst;
	while (fd_lst)
	{
		fd = (int *)fd_lst->data;
		close(*fd);
		fd_lst = fd_lst->next;
	}
}

void	dup_fd(int fd_in, int fd_out)
{
	if (fd_in < 0 && fd_out < 0)
		return ;
	ft_error(dup2(fd_in, STDIN_FILENO), 1);
	ft_error(dup2(fd_out, STDOUT_FILENO), 1);
}

int	wait_pross(pid_t pross)
{
	int	status;

	waitpid(pross, &status, 0);
	while (wait(NULL) != -1)
		;
	return (get_exit_status(status));
}

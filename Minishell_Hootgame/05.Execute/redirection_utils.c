/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:23:26 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/12 05:53:57 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static char	*read_file(char *file)
{
	int		fd;
	char	*str;
	char	*full_str;

	full_str = NULL;
	str = NULL;
	fd = open(file, O_RDONLY);
	ft_error(fd, 1);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		full_str = ft_strjoin_gnl(full_str, str);
		free(str);
	}
	close(fd);
	return (full_str);
}

static char	*expand_file(char *file, int type)
{
	int		fd;
	char	*full_str;
	char	*tmp;

	if (type != TK_WORD)
		return (file);
	full_str = read_file(file);
	if (full_str)
	{
		tmp = full_str;
		full_str = expand_word(full_str, 0, 0);
		free(tmp);
		fd = open(file, O_RDWR | O_TRUNC);
		ft_error(fd, 1);
		ft_printf(fd, "%s", full_str);
		free(full_str);
		close(fd);
	}
	return (file);
}

void	run_redirect(t_list *redirect, t_fd fd_rd, int *fd_in, int *fd_out)
{
	if (!redirect)
		return ;
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
			fd_rd.fd_rd = open(expand_file(redirect->next->value,
						redirect->next->type), O_RDONLY);
		ft_error(fd_rd.fd_rd, 1);
		redirect = redirect->next->next;
	}
	if (fd_rd.fd_rd >= 0)
		*fd_in = fd_rd.fd_rd;
	if (fd_rd.fd_wr >= 0)
		*fd_out = fd_rd.fd_wr;
}

int	run_builtin(t_tree *root, char **cmd, int fd_in, int fd_out)
{
	int	i;

	i = -1;
	if (root && !g_pub.should_fork)
		run_redirect(root->redirect_mode,
			(t_fd){.fd_rd = -2, .fd_wr = -2},
			&fd_in, &fd_out);
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (dup_fd(fd_in, fd_out), echo_cmd(&cmd[1]), SUCCESS);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		return (dup_fd(fd_in, fd_out), cd_cmd(cmd[1]), SUCCESS);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		return (dup_fd(fd_in, fd_out), exit_cmd(&cmd[1]), SUCCESS);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		return (dup_fd(fd_in, fd_out), pwd_cmd(), SUCCESS);
	else if (ft_strcmp(cmd[0], "export") == 0)
		return (dup_fd(fd_in, fd_out), export_cmd(cmd), SUCCESS);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		return (dup_fd(fd_in, fd_out), unset_cmd(&cmd[1]), SUCCESS);
	else if (ft_strcmp(cmd[0], "env") == 0)
		return (dup_fd(fd_in, fd_out), env_cmd(), SUCCESS);
	else
		return (FAIL);
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

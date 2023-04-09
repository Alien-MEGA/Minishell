/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:53:56 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 00:41:28 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

static char	*generator_tmp(void)
{
	char		*gen_tmp;
	int			*num;
	int			status;

	num = malloc(4);
	status = read(open("/dev/urandom", O_RDONLY), num, 4);
	gen_tmp = ft_strjoin("/tmp/tmp-", ft_itoa(*num));
	return (free(num), gen_tmp);
}

static void	ft_read_tmp(char *tmp_file, char *limiter)
{
	char	*str;
	int		fd_tmp;

	fd_tmp = open(tmp_file, O_RDWR | O_TRUNC | O_CREAT, 0600);
	ft_error(fd_tmp, 1);
	limiter = ft_strjoin(limiter, "\n");
	while (1)
	{
		ft_printf(1, "Heredoc > ");
		str = get_next_line(0);
		if (!str || ft_strncmp(str, limiter, ft_strlen(limiter)) == 0)
			break ;
		ft_printf(fd_tmp, "%s", str);
		free(str);
	}
	free(limiter);
	close(fd_tmp);
}

static char	*here_doc(char *delimiter)
{
	char	*tmp_file;

	tmp_file = generator_tmp();
	ft_read_tmp(tmp_file, delimiter);
	if (g_pub.is_sigset)
		unlink(tmp_file);
	return (tmp_file);
}

static void	change_value(t_list *lst, char *new_value)
{
	char	*tmp;

	tmp = lst->value;
	lst->value = new_value;
	free(tmp);
}

// Note : I think there is a problem if : << li"m" need expand before
void	run_here_doc(t_tree *tree)
{
	t_list	*lst;
	char	*tmp_file;

	if (!tree)
		return ;
	run_here_doc(tree->left);
	run_here_doc(tree->right);
	if (!tree->redirect_mode)
		return ;
	lst = tree->redirect_mode;
	while (lst)
	{
		if (lst->type == TK_HERE_DOC)
		{
			tmp_file = here_doc(lst->next->value);
			change_value(lst->next, tmp_file);
		}
		lst = lst->next->next;
	}
}

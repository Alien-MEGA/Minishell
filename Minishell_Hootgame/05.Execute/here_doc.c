/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:53:56 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/04 00:37:08 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

static char	*generator_tmp(void)
{
	char		*gen_tmp;
	int			*num;
	int			status;

	num = malloc(10);
	status = read(open("/dev/urandom", O_RDONLY), num, 10);
	if (status == -1)
		return (free(num), ft_strdup("tmp-"));
	gen_tmp = ft_strjoin("/tmp/tmp-", ft_itoa(*num));
	return (free(num), gen_tmp);
}

static void	ft_read_tmp(char *tmp_file, char *limiter, int should_expand)
{
	char	*str;
	int		fd_tmp;
	char	*tmp;

	fd_tmp = open(tmp_file, O_RDWR | O_TRUNC | O_CREAT, 0600);
	ft_error(fd_tmp, 1);
	limiter = ft_strjoin(limiter, "\n");
	while (1)
	{
		ft_printf(2, "Heredoc > ");
		str = get_next_line(0);
		 if (should_expand == TRUE && iscontain_var(str))
		 {
			tmp = str;
			str = expand_word(str, 0, 0);
			free(tmp);
		 }
		if (!str || ft_strncmp(str, limiter, ft_strlen(limiter)) == 0)
			break ;
		ft_printf(fd_tmp, "%s", str);
		free(str);
	}
	free(limiter);
	close(fd_tmp);
}

char	*here_doc(t_list *delimiter)
{
	char	*tmp_file;
	int		should_expand;

	should_expand = TRUE;
	if (delimiter->type == TK_DOUBLE_QUOTE)
		should_expand = FALSE;
	tmp_file = generator_tmp();
	ft_read_tmp(tmp_file, delimiter->value, should_expand);
	if (g_pub.is_sigset)
		unlink(tmp_file);
	return (tmp_file);
}

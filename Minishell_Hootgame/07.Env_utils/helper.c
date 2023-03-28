/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:46:50 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/28 18:40:16 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

t_loc	ini_loc(int i, int j)
{
	t_loc	loc;

	loc.i = i;
	loc.j = j;
	return (loc);
}
void reset_io()
{
	char *path;
	path = ttyname(1);
	ft_error_str(path, 1);
	int fd = open(path, O_RDONLY);
	ft_error(fd, 1);
	ft_error(dup2(fd, 1), 1);
	close(fd);
	path = ttyname(0);
	ft_error_str(path, 0);
	fd = open(path, O_RDONLY);
	ft_error(fd, 0);
	ft_error(dup2(fd, 0),1);
	close(fd);
}

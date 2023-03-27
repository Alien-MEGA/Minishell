/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:46:50 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/27 23:13:11 by ebennamr         ###   ########.fr       */
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
	ft_error(dup(fd, 1), 1);
	close(fd);
	path = ttyname(0);
	ft_error_str(path, 0);
	int fd = open(path, O_RDONLY);
	ft_error(fd, 0);
	ft_error(dup(fd, 0),1);
	close(fd);
}

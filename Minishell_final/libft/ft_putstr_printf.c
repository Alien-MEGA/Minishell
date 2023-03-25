/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:19:31 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/06 18:05:40 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s, int fd)
{
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	return (write(fd, s, ft_strlen(s)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pos_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:56:26 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

int	ft_putnbr_pos(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnbr_pos(n / 10, fd);
		len += ft_putnbr_pos(n % 10, fd);
	}
	if (n < 10)
		len += ft_putchar(n + 48, fd);
	return (len);
}

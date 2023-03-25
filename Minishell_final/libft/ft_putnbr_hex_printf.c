/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:57:38 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/06 18:03:59 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex(unsigned int n, int ul, int fd)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putnbr_hex(n / 16, ul, fd);
		len += ft_putnbr_hex(n % 16, ul, fd);
	}
	if (n < 10)
		len += ft_putchar(n + 48, fd);
	else if (n >= 10 && n <= 15)
	{
		if (ul == 0)
			len += ft_putchar(n + 87, fd);
		if (ul == 1)
			len += ft_putchar(n + 55, fd);
	}
	return (len);
}

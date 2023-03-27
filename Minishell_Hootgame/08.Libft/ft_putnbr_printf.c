/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:12:40 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/06 18:04:45 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n, int fd)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putchar('-', fd);
		len += ft_putchar('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		n = n * (-1);
		len += ft_putchar('-', fd);
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10, fd);
		len += ft_putnbr(n % 10, fd);
	}
	if (n < 10)
		len += ft_putchar(n + 48, fd);
	return (len);
}

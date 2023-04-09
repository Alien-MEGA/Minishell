/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:13:45 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

static int	ft_putptr_do(unsigned long long n, int fd)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putptr_do(n / 16, fd);
		len += ft_putptr_do(n % 16, fd);
	}
	else if (n < 10)
		len += ft_putchar(n + 48, fd);
	else if (n >= 10 && n <= 15)
	{
		len += ft_putchar(n + 87, fd);
	}
	return (len);
}

int	ft_putptr(unsigned long long n, int fd)
{
	size_t	len;

	len = 0;
	len += ft_putstr("0x", fd);
	len += ft_putptr_do(n, fd);
	return (len);
}

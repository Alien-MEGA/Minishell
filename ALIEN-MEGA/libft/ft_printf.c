/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:04:48 by reben-ha          #+#    #+#             */
/*   Updated: 2023/02/06 18:24:56 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_han(char han, va_list arg, int fd)
{
	int		len;

	len = 0;
	if (han == 'c')
		len += ft_putchar(va_arg(arg, int), fd);
	else if (han == 's')
		len += ft_putstr(va_arg(arg, char *), fd);
	else if ((han == 'd') || (han == 'i'))
		len += ft_putnbr(va_arg(arg, int), fd);
	else if (han == 'u')
		len += ft_putnbr_pos(va_arg(arg, unsigned int), fd);
	else if (han == 'x')
		len += ft_putnbr_hex(va_arg(arg, unsigned int), 0, fd);
	else if (han == 'X')
		len += ft_putnbr_hex(va_arg(arg, unsigned int), 1, fd);
	else if (han == 'p')
		len += ft_putptr(va_arg(arg, unsigned long long), fd);
	else if (han == '%')
		len += ft_putchar('%', fd);
	else
		len += ft_putchar(han, fd);
	return (len);
}

void	ft_printf(int fd, const char *str, ...)
{
	va_list	arg;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			len += ft_han(str[i + 1], arg, fd);
			i++;
		}
		else
			len += ft_putchar(str[i], fd);
		i++;
	}
	va_end(arg);
}

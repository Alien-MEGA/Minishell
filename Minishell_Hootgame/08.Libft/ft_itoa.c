/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:45:54 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

static int	tolen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_check(int n, char *result)
{
	if (n == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		result[0] = '-';
		n = n * (-1);
	}
	if (n == 0)
		result[0] = '0';
	return (n);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = tolen(n);
	result = (char *)malloc((len * sizeof(char)) + 1);
	ft_error_str(result, 1);
	n = ft_check(n, result);
	result[len] = '\0';
	while (n != 0)
	{
		result[--len] = (n % 10) + 48;
		n = n / 10;
	}
	return (result);
}

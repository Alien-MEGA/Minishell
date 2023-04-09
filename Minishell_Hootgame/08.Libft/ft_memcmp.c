/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:27:14 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t nulb)
{
	size_t			i;
	unsigned char	*str1x;
	unsigned char	*str2x;

	i = 0;
	str1x = (unsigned char *)str1;
	str2x = (unsigned char *)str2;
	while (i < nulb)
	{
		if (str1x[i] != str2x[i])
			return (str1x[i] - str2x[i]);
		i++;
	}
	return (0);
}

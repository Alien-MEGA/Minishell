/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:20:23 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/06 18:24:15 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t			i;
	unsigned char	*s1x;
	unsigned char	*s2x;

	if (str1 == NULL || str2 == NULL)
		return (-1);
	s1x = (unsigned char *)str1;
	s2x = (unsigned char *)str2;
	i = 0;
	while (i < size && (s1x[i] != '\0' || s2x[i] != '\0'))
	{
		if (s1x[i] != s2x[i])
			return (s1x[i] - s2x[i]);
		i++;
	}
	return (0);
}

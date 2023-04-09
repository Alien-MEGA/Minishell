/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:11:26 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	start;
	size_t	destsize;

	if (len == 0 && dest == 0)
		return (ft_strlen(src));
	destsize = ft_strlen(dest);
	start = destsize;
	i = 0;
	if (destsize >= len)
		return (ft_strlen(src) + len);
	while (i < (len - destsize - 1) && src[i])
	{
		dest[start + i] = src[i];
		i++;
	}
	dest[start + i] = '\0';
	return ((destsize + ft_strlen(src)));
}

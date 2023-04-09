/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:15:29 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t nulb)
{
	size_t	i;
	char	*destx;
	char	*srcx;

	destx = (char *)dest;
	srcx = (char *)src;
	i = 0;
	if (destx == NULL && srcx == NULL)
		return (NULL);
	while (i < nulb)
	{
		destx[i] = srcx[i];
		i++;
	}
	return (destx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:20:47 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nedlsize;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	nedlsize = ft_strlen(needle);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0] && len - i >= nedlsize
			&& (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

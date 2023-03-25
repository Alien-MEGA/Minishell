/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:18:55 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/01 21:49:45 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*strout;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	strout = (char *)malloc(len * sizeof(char) + 1);
	ft_error_str(strout, 1);
	while (str[i] != '\0')
	{
		if (i >= start && j < len)
		{
			strout[j] = str[i];
			j++;
		}
		i++;
	}
	strout[j] = '\0';
	return (strout);
}

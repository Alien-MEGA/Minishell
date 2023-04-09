/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:22:41 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

size_t	ft_matlen(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

char	**ft_matrixdup(char **matrix)
{
	char	**new_matrix;
	int		i;

	if (!matrix)
		return (NULL);
	new_matrix = (char **)malloc((ft_matlen(matrix) + 1) * sizeof(char *));
	ft_error_str(new_matrix, 1);
	i = -1;
	while (matrix[++i])
		new_matrix[i] = ft_strdup(matrix[i]);
	new_matrix[i] = NULL;
	return (new_matrix);
}

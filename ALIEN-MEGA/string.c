/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:53:30 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/06 17:52:34 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	indexofchar(char *line, char c)
{
	int i;

	i = 0;
	if (line == 0)
		return (-1);
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}

	return (-1);
}

static void	mat_copy_free(char **res, char **s1,char **s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		res[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = NULL;
	free(s1);
	free(s2);
}
char	**mat_join(char **s1, char **s2)
{
	char	**pt2;
	char	**pt1;
	char	**res;

	pt1 = ft_matrixdup(s1);
	pt2 = ft_matrixdup(s2);
	res = (char **)malloc((ft_matlen(s1) + ft_matlen(s2) + 1) * sizeof(char *));
	ft_error_str(res, 1);
	printf("bfore copy and free \n");
	mat_copy_free(res, pt1, pt2);
	printf("after copy and free \n");

	return (res);
}

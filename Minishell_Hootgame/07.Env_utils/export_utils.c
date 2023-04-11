/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:33:01 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/11 02:10:48 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

int	check_var(char *var)
{
	int	i;
	int	len;

	if (var[0] != '_' && !ft_isalpha(var[0]))
		return (FALSE);
	i = 1;
	len = ft_strlen(var);
	while (i < len)
	{
		if (var[i] != '_' && !ft_isalnum(var[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	print_export(char *var)
{
	int	i;
	int	index;

	index = indexofchar(var, '=');
	i = 0;
	printf("%s", DECLARE_X);
	while (var[i])
	{
		printf("%c", var[i]);
		if (i == index)
			printf("\"");
		i++;
	}
	if (index > 0)
		printf("\"\n");
	else
		printf("\n");
}

void	add_to_export(char *content)
{
	int		len;
	char	**tmp;
	int		i;

	i = 0;
	tmp = g_pub.exp_list;
	len = (int)ft_matlen(g_pub.exp_list);
	g_pub.exp_list = malloc(sizeof(char *) * (len + 2));
	ft_error_str(g_pub.exp_list, 1);
	while (i < len)
	{
		g_pub.exp_list[i] = tmp[i];
		i++;
	}
	g_pub.exp_list[i] = content;
	g_pub.exp_list[i + 1] = NULL;
	free(tmp);
}

void	unset_from_exp(char *key)
{
	int	len;
	int	i;

	i = 0;
	len = ft_matlen(g_pub.exp_list);
	if (g_pub.exp_list[0] == NULL)
		return ;
	while (g_pub.exp_list[i] != NULL && ft_strcmp(key, g_pub.exp_list[i]) != 0)
	{
		i++;
	}
	if (i < len)
		free(g_pub.exp_list[i]);
	while (i < len - 1)
	{
		g_pub.exp_list[i] = g_pub.exp_list[i + 1];
		i++;
	}
	g_pub.exp_list[i] = NULL;
}

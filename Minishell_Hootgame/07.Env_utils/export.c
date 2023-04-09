/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:31:34 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:13 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

void	export_to_explist(char *arg)
{
	int	i;

	i = 0;
	if(g_pub.isdef_env == TRUE)
	{
		g_pub.isdef_env = FALSE;
		export_to_env("PATH", ft_strdup(g_pub.path), OPT_CREAT);
		free(g_pub.path);
	}
	while (g_pub.exp_list[i])
	{
		if (ft_strcmp(g_pub.exp_list[i], arg) == 0)
			return ;
			i++;
	}
	add_to_export(arg);
}

int	valid_arg(char *arg)
{
	int		index;
	char	*sub;
	int		bool;

	index = indexofchar(arg, '=');
	if (index < 0)
		return (check_var(arg));
	else if (index >= 1 && arg[index - 1] == '+')
	{
		sub = ft_substr(arg, 0, index - 1);
		bool = check_var(sub);
	}
	else
	{
		sub = ft_substr(arg, 0, index);
		bool = check_var(sub);
	}
	return (free(sub), bool);
}

void	sort_mat(char **arr)
{
	int		len;
	int		j;
	int		i;
	char	*tmp;

	len = ft_matlen(arr);
	if (len < 2)
		return ;
	i = 0;
	j = 0;
	while (arr[i])
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

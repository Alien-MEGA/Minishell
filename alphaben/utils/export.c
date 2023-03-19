/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:31:34 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/15 15:25:19 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../minishell.h"
void	export()
{
	char	**arr;
	int		i;

	i = 0;
	arr = mat_join(g_pub.env, g_pub.exp_list);
	sort_mat(arr);
	while (arr[i])
	{
		print_export(arr[i]);
		i++;
	}
	ft_free(arr);
}

void export_args(char **args)
{
	char	*key;
	char	*value;
	int		opt;

	while(*args)
	{
		if(valid_arg(*args) == FALSE)
		{
			ft_printf(2, "minishell: export: '%s': not a valid identifier\n",*args);
			g_pub.exit_status = 1;
		}
		else if (indexofchar(*args, '=') == -1 && index_in_env(*args) == -1 )
			export_to_explist(ft_strdup(*args));
			else
			{
				fill_key_value_opt(*args, &key, &value, &opt);
				unset_from_exp(key);
				export_to_env(key, value, opt);
				free(key);
				free(value);
			}
		args++;
	}
}

void export_to_explist(char *arg)
{
	int i;
	i = 0;
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
		sub = ft_substr(arg,0 , index - 1);
		bool = check_var(sub);

	}
	else
	{
		sub = ft_substr(arg, 0, index );
		bool = check_var(sub);
	}
	return (free(sub),(bool));
}

void	sort_mat(char **arr)
{
	int len;
	int j;
	int i;
	char *tmp;

	if (len < 2)
		return;
	len = ft_matlen(arr);
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

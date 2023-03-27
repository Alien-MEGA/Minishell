/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:01:49 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/27 02:33:20 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

void	export(void)
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

void	export_args(char **args)
{
	char	*key;
	char	*value;
	int		opt;

	while (*args)
	{
		if (valid_arg(*args) == FALSE)
		{
			ft_printf(2, "minishell: export: '%s': not a valid identifier\n",
				*args);
			g_pub.exit_status = 1;
		}
		else if (indexofchar(*args, '=') == -1 && index_in_env(*args) == -1)
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

void	export_cmd(char **cmd)
{
	g_pub.exit_status = 0;
	if (cmd[1] == NULL)
		export();
	else
		export_args(&cmd[1]);
}

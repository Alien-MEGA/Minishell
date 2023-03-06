/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:31:34 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/06 20:48:22 by ebennamr         ###   ########.fr       */
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
		printf("%s%s\n",DECLARE_X, arr[i]);
		i++;
	}
	ft_free(arr);
}

void export_args(char **args)
{

}
void export_to_explist(char *arg)
{
	
}

int valid_arg(char args)
{

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

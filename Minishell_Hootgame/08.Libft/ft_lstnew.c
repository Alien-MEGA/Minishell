/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:14:15 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

t_list	*ft_lstnew(int type, char *value, void *data)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	ft_error_str(newnode, 1);
	newnode->type = type;
	newnode->value = value;
	newnode->data = data;
	newnode->next = NULL;
	return (newnode);
}

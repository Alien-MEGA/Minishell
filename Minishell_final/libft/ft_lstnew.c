/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:14:15 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/06 14:37:03 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:17:22 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/01 21:18:48 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(int status, int code)
{
	if (status == FAIL)
		return (perror("Error "), exit(code));
}

void	ft_error_str(void *status, int code)
{
	if (status == NULL)
		return (perror("Error "), exit(code));
}

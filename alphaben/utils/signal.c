/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:30:48 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/12 14:05:18 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void sigint_handler(int sig)
{

	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	ft_printf(2, PROMPT_1);
	rl_redisplay();


	g_pub.exit_status = sig;
}
void sigquit_handler(int sig)
{

}
void	sig_inint()
{
	signal(SIGINT,sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}

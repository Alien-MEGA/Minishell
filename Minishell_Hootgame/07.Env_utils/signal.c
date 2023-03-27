/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:30:48 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/27 02:45:45 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

void	sigint_handler(int sig)
{
	char	*prompt;

	prompt = get_prompt(get_pwd());
	printf("\n");
	rl_on_new_line();
	if (isatty(0))
		ft_printf(1, prompt);
	rl_replace_line("", 0);
	rl_redisplay();
	free(prompt);
	g_pub.exit_status = sig;
}

void	sigquit_handler(int sig)
{
	(void)sig;
}

void	sig_inint(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}

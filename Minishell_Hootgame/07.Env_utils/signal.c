/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:30:48 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/27 19:56:00 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

void	sigint_handler(int sig)
{
	char	*prompt;
	g_pub.exit_status = 130;
	(void)sig;
	prompt = get_prompt(get_pwd());
	printf("\n");
	rl_on_new_line();
	if (isatty(0))
		ft_printf(1, prompt);
	rl_replace_line("", 0);
	rl_redisplay();
	free(prompt);
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

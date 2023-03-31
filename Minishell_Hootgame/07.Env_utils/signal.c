/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:30:48 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/31 21:57:25 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

static void sigint_handler(int sig)
{
	char *prompt;
	g_pub.exit_status = 130;
	(void)sig;
	prompt = get_prompt(get_pwd());
	printf("\n");
	if (isatty(0))
		ft_printf(1, prompt);
	rl_replace_line("", 0);
	rl_redisplay();
	free(prompt);
}

void sig_empty(int sig)
{
	(void)sig;
}

static void sig_child(int sig)
{
	if (sig == SIGINT)
		exit(130);
	if (sig == SIGQUIT)
		exit(131);
}

static void sig_herdoc(int sig)
{
	g_pub.is_sigset = TRUE;
	close(0);
}

void sig_inint(int type)
{
	if (type == TP_SIG_MAIN)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, sig_empty);
	}
	else if (type == TP_SIG_CHILD)
	{
		signal(SIGINT, sig_child);
		signal(SIGQUIT, sig_child);
	}
	else if (type == TP_SIG_HRDC)
	{
		g_pub.is_sigset = FALSE;
		signal(SIGINT, sig_herdoc);
		signal(SIGQUIT, sig_empty);
	}
	else if (type == TP_SIG_EMPTY)
	{
		signal(SIGINT, sig_empty);
		signal(SIGQUIT, sig_empty);
	}
}

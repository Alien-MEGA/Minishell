/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:30:48 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/11 21:39:43 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static void	sigint_handler(int sig)
{
	g_pub.exit_status = 1;
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sig_empty(int sig)
{
	(void)sig;
}

static void	sig_child(int sig)
{
	if (sig == SIGINT)
		exit(130);
	if (sig == SIGQUIT)
		exit(131);
}

static void	sig_herdoc(int sig)
{
	g_pub.is_sigset = TRUE;
	g_pub.exit_status = 1;
	printf("\n");
	close(0);
}

void	sig_inint(int type)
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

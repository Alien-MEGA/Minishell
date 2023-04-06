/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:49:52 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/06 23:45:53 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

/* ==============> Color <============== */
# define RED     "\033[31;3m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE	"\033[34;1m"
# define MAGENTA "\033[0;35m"
# define CYAN    "\033[0;36m"
# define WHITE   "\033[0;37m"
# define RESET   "\033[0m"

/* ==============> Tools <============== */
# define SP_CHAR "'\"<>()| \t"
# define CL_DEFAULT "\e[0m"
# define PROMPT "\e[1;32m┌──(Minishell㉿Aliens)\n└─$ \e[0m"
# define PROMPT_1 "\e[1;32m┌──(Minishell㉿Aliens)\n"
# define PROMPT_2 "\e[1;32m└─$ \e[0m"
# define PROMPT_ONE "\n\e[1;32m┌──(Minishell㉿Aliens)-[/"
# define PROMPT_TWO "]\n└─$ \e[0m"

#define PROMPT_P1 "\n\033[34;1m┌──(\033[0;33mMini㉿Shell\033[34;1m)-[\033[0;33m"
#define PROMPT_P2 "\033[34;1m]-["
# define PROMPT_P3 "\033[34;1m]\n└─$ \e[0m"

//====== boolean ========
# define FALSE 0
# define TRUE 1
# define SUCCESS 0
//====== option ========
# define OPT_CREAT 0
# define OPT_APPEND 1
//====== tree side ========
# define LEFT 0
# define RIGHT 1
// type ========
# define T_O 0
# define T_R 1
# define T_W 2
// sig type ======
# define TP_SIG_MAIN 0
# define TP_SIG_HRDC 1
# define TP_SIG_CHILD 2
# define TP_SIG_EMPTY 3
/* ==============> String  <============== */
# define SHLVL "SHLVL=1"
# define DEFAULT_PATH "/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."
# define DECLARE_X "declare -x "

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:49:52 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/21 20:00:50 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

/* ==============> Color <============== */
# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
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
# define PROMPT_ONE "\n\e[1;32m┌──(Minishell㉿Aliens)-[./"
# define PROMPT_TWO "]\n└─$ \e[0m"
//====== boolean ========
# define FALSE 0
# define TRUE 1
//====== option ========
# define OPT_CREAT 0
# define OPT_APPEND 1
//====== tree side ========
# define LEFT 0
# define RIGHT 1
// type ========
# define TP_OPER 0
# define TP_REDIR 1
# define TP_WORD 2
/* ==============> String  <============== */
# define SHLVL "SHLVL=1"
# define DEFAULT_PATH "/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."
# define DECLARE_X "declare -x "

#endif

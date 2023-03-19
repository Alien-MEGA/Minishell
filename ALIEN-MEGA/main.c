/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:09:12 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/19 17:17:43 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <dirent.h>


int main()
{
	int fd[2];
	pipe(fd);
	dup2(fd[0], STDIN_FILENO);
	printf("%d \n", isatty(fd[0]));
	printf("%d \n", isatty(STDIN_FILENO));
}
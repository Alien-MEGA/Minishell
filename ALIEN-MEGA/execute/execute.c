/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:44:28 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/17 13:58:58 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_fd	creat_pipe(void)
{
	int 	fd[2];
	t_fd	pipe_fd;

	ft_error(pipe(fd), 1);
	pipe_fd.fd_rd = fd[];
	pipe_fd.fd_wr = fd[];
	
}

unsigned int	execute(t_tree *root, int fd_in, int fd_out)
{


	if (root->lst->type == TK_OR || root->lst->type == TK_AND)
	{
		execute(root->left, fd_in, fd_out);
		execute(root->right, fd_in, fd_out);
	}
	else if (root->lst->type == TK_PIPE)
	{
		creat_pipe();
		execute(root->left, fd_in, fd_out);
		execute(root->right, fd_in, fd_out);		
	}
	else if (root->lst->type == TK_WORD)
	{
		
	
	



	



	}


	
}

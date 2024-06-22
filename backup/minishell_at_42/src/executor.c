/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:13:32 by npiyapan          #+#    #+#             */
/*   Updated: 2024/06/22 16:37:42 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	executor(t_tools *tools)
{
	int			fd[2];
	static int	i = 0;
	int			fd_in;

	fd_in = STDIN_FILENO;
	while (tools->cmds)
	{
		if (tools->cmds->next){
			if (pipe(fd) == -1)
				perror("pipe error");
		}
		tools->pid[i] = fork();
		printf("tools.pid[%d] = %d\n", i, tools->pid[i]);
		if (tools->pid[i]  == -1)	perror("fork");
		if (tools->pid[i] == 0){ // child process
			if (tools->cmds->next){
				dprintf(2, "dup stdout\n");
				if (dup2(fd[1], STDOUT_FILENO) == -1)	perror("dup2");
				dprintf(2, "fd[1] = %d\n", fd[1]);
				if (close(fd[1]) == -1)	perror("close fd1");
			}
			if (tools->cmds->prev){
				dprintf(2, "dup stdin\n");
				if (dup2(fd_in, STDIN_FILENO) == -1)	perror("dup2");
				dprintf(2, "fd[0] = %d\n", fd[0]);
				if (close(fd_in) == -1)	perror("close fd0");
			}
			dprintf(2, "do command %s\n", tools->cmds->str[0]);
			basic_cmd2(tools);
		}
		// if (dup2(fd[0], STDIN_FILENO) == -1)	perror("dup2");
		// dprintf(2, "fd[0] in parent = %d\n", fd[0]);
		// if (close(fd[0]) == -1)	perror("close fd0");
		i++;
		if (tools->cmds->next)
		{
			tools->cmds = tools->cmds->next;
		}
		else
			break;
	}
	dprintf(2, "exit while loop pid[%d] = %d\n", i - 1, tools->pid[i - 1]);
	waitpid(tools->pid[i - 1], NULL, 0);
	return (0);
}

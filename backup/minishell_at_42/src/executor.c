/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:13:32 by npiyapan          #+#    #+#             */
/*   Updated: 2024/06/18 14:39:44 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	executor(t_tools *tools)
{
	int		fd[2];
	int		fork_id;

	while (tools->cmds)
	{
		if (pipe(fd) == -1)
			printf("pipe error\n");
		printf("test\n");
		fork_id = fork();
		if (fork_id == -1){
			ft_error(5, tools);
		}
		printf("fork_id = %d\n", fork_id);
		if (fork_id == 0){ // child process
			if (tools->cmds->prev){
				write(2, "have prev\n", 10);
				if (dup2(fd[0], STDIN_FILENO) == -1)
					ft_error(4, tools);
				// read(fd[0], "test read to fd1\n", 17);
			}else {
				write(2, "not have prev\n", 14);
			}
			if (close(fd[0] == -1))
				printf("error to close fd\n");
			if (tools->cmds->next){
				write(2, "have next\n", 10);
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					perror("dup2");
				write(2, "test write to fd1\n", 18);
				write(fd[1], "test write to fd1\n", 18);
			}else {
				write(2, "not have next\n", 14);
			}
			if (close(fd[1]) == -1)
				printf("error to close fd\n");
			// basic_cmd2(tools);
			
			exit(0);
		}
		if (tools->cmds->next)
			tools->cmds = tools->cmds->next;
		else
			break;
	}
	waitpid(fork_id, NULL, 0);
	return (0);
}

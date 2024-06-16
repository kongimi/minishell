/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:13:32 by npiyapan          #+#    #+#             */
/*   Updated: 2024/06/16 13:44:48 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

// t_cmds	*call_expander(t_tools *tools, t_cmds *cmd)
// {
// 	t_lexer	*start;

// 	cmd->str = expander(tools, cmd->str);
// 	start = cmd->redirections;
// 	while (cmd->redirections)
// 	{
// 		if (cmd->redirections->token != LESS_LESS)
// 			cmd->redirections->str
// 				= expander_str(tools, cmd->redirections->str);
// 		cmd->redirections = cmd->redirections->next;
// 	}
// 	cmd->redirections = start;
// 	return (cmd);
// }

// void	dup_cmd(t_cmds *cmd, t_tools *tools, int end[2], int fd_in)
// {
// 	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
// 		ft_error(4, tools);
// 	close(end[0]);
// 	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
// 		ft_error(4, tools);
// 	close(end[1]);
// 	if (cmd->prev)
// 		close(fd_in);
// 	handle_cmd(cmd, tools);
// }

// int	ft_fork(t_tools *tools, int end[2], int fd_in, t_cmds *cmd)
// {
// 	static int	i = 0;

// 	if (tools->reset == true)
// 	{
// 		i = 0;
// 		tools->reset = false;
// 	}
// 	tools->pid[i] = fork();
// 	if (tools->pid[i] < 0)
// 		ft_error(5, tools);
// 	if (tools->pid[i] == 0)	// child process
// 		dup_cmd(cmd, tools, end, fd_in);
// 	i++;
// 	return (EXIT_SUCCESS);
// }

int	executor(t_tools *tools)
{
	int		fd[2];
	int		fork_id;
	t_cmds	*tmp_cmds;
	int		i = 0;

	tmp_cmds = tools->cmds;
	if (tmp_cmds)
		printf("cmd = %s\n", tmp_cmds->str[0]);
	else
		printf("not have cmd\n");
	while (i++ < 2)
	{
		printf("in executor\n");
		if (pipe(fd) == -1){
			ft_putendl_fd("error from try pipe", STDOUT_FILENO);
			return 1;
		}
		fork_id = fork();
		if (fork_id == -1){
			ft_putendl_fd("error from try fork", STDOUT_FILENO);
			return 2;
		}
		if (fork_id == 0){ // child process
			printf("child process\n");
			if (dup2(fd[0], STDIN_FILENO) || dup2(fd[1], STDOUT_FILENO)){
				// ft_putendl_fd("error from try fork", STDOUT_FILENO);
				perror("dup2");
				return 2;
			}

			printf("child process2\n");
			close(fd[1]);
			close(fd[0]);
			printf("child process3\n");
			basic_cmd2(tools);
			exit(0);
		}
		
		
		if  (tmp_cmds->next)
			tmp_cmds = tmp_cmds->next;
		else
			waitpid(fork_id, NULL, 0);
		// }
		
	}
	return (0);
}

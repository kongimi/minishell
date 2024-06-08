/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:13:32 by npiyapan          #+#    #+#             */
/*   Updated: 2024/06/08 15:09:48 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

int	ft_fork(t_tools *tools, int end[2], int fd_in, t_cmds *cmd)
{
	static int	i = 0;

	if (tools->reset == true)
	{
		i = 0;
		tools->reset = false;
	}
	tools->pid[i] = fork();
	if (tools->pid[i] < 0)
		ft_error(5, tools);
	if (tools->pid[i] == 0)
		dup_cmd(cmd, tools, end, fd_in);
	i++;
	return (EXIT_SUCCESS);
}

int	executor(t_tools *tools)
{
	int		end[2];
	int		fd_in;
	t_cmds	*tmp_cmds;

	tmp_cmds = *tools->cmds;
	fd_in = STDIN_FILENO;
	while (tools->cmds)
	{
		
		// tools->cmds = call_expander(tools, tools->cmds);
		if (tmp_cmds->next)
			pipe(end);
		// send_heredoc(tools, tools->cmds);
		ft_fork(tools, end, fd_in, tools->cmds);
		close(end[1]);
		if (tmp_cmds->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(tools, end, tools->cmds);
		if (tmp_cmds->next)
			tools->cmds = tmp_cmds->next;
		else
			break ;
	}
	pipe_wait(tools->pid, tools->pipes);
	tools->cmds = ft_cmdsfirst(tools->cmds);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:49:35 by npiyapan          #+#    #+#             */
/*   Updated: 2024/04/25 16:51:42 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	my_loop(t_tools *tools)
{
	int	pid_res;
	int	status;

	tools->args = readline(READLINE_MSG);
	printf("%s\n", tools->args);
	if (ft_strncmp(tools->args, "exit", 4) == 0)
	{
		free (tools->args);
		g_global.exit_status = 1;
		return ;
	}
	tools->cmds[0] = malloc(sizeof(char) * (ft_strlen(tools->args) + 1));
	tools->cmds[0] = ft_strdup(tools->args);
	tools->cmds[1] = 0;
	tools->cmds[2] = 0;
	free (tools->args);
	pid_res = fork();
	if (pid_res < 0)
		ft_putendl_fd("fork error", 2);
	if (pid_res == 0)
	{
		if (!access(tools->cmds[0], F_OK))
			execve(tools->cmds[0], tools->cmds, tools->envi);
	}
	waitpid(pid_res, &status, 0);
	printf("waitpid status = %d\n", status);
}

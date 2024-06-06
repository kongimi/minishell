/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:49:35 by npiyapan          #+#    #+#             */
/*   Updated: 2024/06/06 13:33:41 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/my_loop.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	ft_trim(t_tools *tools)
{
	char	*tmp;

	tmp = ft_strtrim(tools->args, " ");
	free (tools->args);
	if (!tmp)
	{
		ft_putendl_fd("fail from ft_trim", 2);
		g_global.exit_status = 1;
		exit (1);
	}
	tools->args = ft_strdup(tmp);
	free (tmp);
	if (!tools->args)
	{
		free (tools->args);
		ft_putendl_fd("fail from strdup in my_loop", 2);
		g_global.exit_status = 1;
		exit (1);
	}
}

void	ft_print_err(char *str1, char *str2)
{
	char	*str3;

	str3 = ft_strjoin(str1, str2);
	if (!str3)
		ft_putendl_fd("error from ft_print_err", 2);
	ft_putendl_fd(str3, 2);
}

void	fork_error(t_tools *tools)
{
	free(tools->args);
	ft_putendl_fd("fail to fork", 2);
	g_global.exit_status = 1;
}

void	basic_cmd(t_tools *tools)
{
	t_loop_tools	my_tools;
	t_cmds			*tmp_cmds;

	// check_exit(tools);

	tmp_cmds = *tools->cmds;
	my_tools.fork_value = fork();
	if (my_tools.fork_value < 0)
		fork_error(tools);
	if (my_tools.fork_value == 0)
	{
		if (!access(tmp_cmds->str[0], F_OK))
			execve(tmp_cmds->str[0], tmp_cmds->str, tools->envi);
		my_tools.i = 0;
		while (tools->paths[my_tools.i])
		{
			my_tools.tmp = ft_strjoin(tools->paths[my_tools.i], tmp_cmds->str[0]);
			if (!access(my_tools.tmp, F_OK))
				execve(my_tools.tmp, tmp_cmds->str, tools->envi);
			free (my_tools.tmp);
			my_tools.i++;
		}
		ft_print_err("command not found : ", tools->args);
		exit (0);
	}
	waitpid(my_tools.fork_value, &my_tools.status, 0);
	free_arr(tmp_cmds->str);
}

void	my_loop(t_tools *tools)
{
	tools->args = readline(READLINE_MSG);
	if (ft_strncmp(tools->args, "exit", 4) == 0)
	{
		if (tools->args)
			free (tools->args);
		g_global.exit_status = 1;
		return ;
	}
	ft_trim(tools);
	add_history(tools->args);
	if (!token_analyze(tools))
	{
		ft_putendl_fd("fail to add new node", 2);
		free(tools->args);
		exit (0);
	}
	parser(tools);
	basic_cmd(tools);
	free(tools->args);
}

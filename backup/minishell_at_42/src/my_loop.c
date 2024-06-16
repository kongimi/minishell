/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:49:35 by npiyapan          #+#    #+#             */
/*   Updated: 2024/06/16 15:44:09 by npiyapan         ###   ########.fr       */
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

void	basic_cmd2(t_tools *tools)
{
	t_cmds			*tmp_cmds;
	char			*tmp;
	int				i;

	tmp_cmds = tools->cmds;
	if (!access(tmp_cmds->str[0], X_OK))
			execve(tmp_cmds->str[0], tmp_cmds->str, tools->envi);
		i = 0;
		while (tools->paths[i])
		{
			tmp = ft_strjoin(tools->paths[i], tmp_cmds->str[0]);
			if (!access(tmp, F_OK))
				execve(tmp, tmp_cmds->str, tools->envi);
			free (tmp);
			i++;
		}
		ft_print_err("command not found : ", tools->args);
		exit (0);
}

void	basic_cmd(t_tools *tools)
{
	t_loop_tools	my_tools;
	t_cmds			*tmp_cmds;

	// check_exit(tools);

	tmp_cmds = tools->cmds;
	my_tools.fork_value = fork();
	if (my_tools.fork_value < 0)
		fork_error(tools);
	if (my_tools.fork_value == 0)
	{
		if (!access(tmp_cmds->str[0], X_OK))
			execve(tmp_cmds->str[0], tmp_cmds->str, tools->envi);
		my_tools.i = 0;
		while (tools->paths[my_tools.i])
		{
			my_tools.tmp = ft_strjoin(tools->paths[my_tools.i], tmp_cmds->str[0]);
			if (!access(my_tools.tmp, X_OK))
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

int	ft_error(int error, t_tools *tools)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (error == 0)
		ft_putstr_fd("syntax error near unexpected token 'newline'\n",
			STDERR_FILENO);
	else if (error == 1)
		ft_putstr_fd("memory error: unable to assign memory\n", STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd("syntax error: unable to locate closing quotation\n",
			STDERR_FILENO);
	else if (error == 3)
		ft_putstr_fd("Parser problem\n", STDERR_FILENO);
	else if (error == 4)
		ft_putstr_fd("Failed to create pipe\n", STDERR_FILENO);
	else if (error == 5)
		ft_putstr_fd("Failed to fork\n", STDERR_FILENO);
	else if (error == 6)
		ft_putstr_fd("outfile: Error\n", STDERR_FILENO);
	else if (error == 7)
		ft_putstr_fd("infile: No such file or directory\n", STDERR_FILENO);
	else if (error == 8)
		ft_putendl_fd("Path does not exist", STDERR_FILENO);
	reset_tools(tools);
	return (EXIT_FAILURE);
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
	if (!tools->pipes)
		basic_cmd(tools);
	else
	{
		printf("have pipes\n");
	}
	tools->pipes = 0;
	free(tools->args);
}

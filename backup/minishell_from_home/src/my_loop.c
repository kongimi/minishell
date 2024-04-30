/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:49:35 by npiyapan          #+#    #+#             */
/*   Updated: 2024/04/28 12:33:28 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#define READLINE_MSG	"\033[1;36mminishell\033[34m$ \033[0m"

void	init_cmd(t_tools *tools)
{
	char	**str;
	// int		arg_size;
	t_cmds	*cmd_tmp;

	cmd_tmp = malloc(sizeof(t_cmds));
	if (!cmd_tmp)
		print_error("fail to malloc t_cmds", 2);
	str = ft_calloc(2, sizeof(char *));
	if (!str)
		print_error("Fail to calloc in init_cmd", 2);
	str[0] = ft_strdup(tools->args);
	str[1] = 0;
	cmd_tmp->str = str;
	cmd_tmp->next = NULL;
	cmd_tmp->prev = NULL;
	tools->cmds = cmd_tmp;
}

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

void	my_loop(t_tools *tools)
{
	char	*tmp;
	int		fork_value;
	int		status;
	int		i;

	tools->args = readline(READLINE_MSG);
	ft_trim(tools);
	add_history(tools->args);
	init_cmd(tools);
	if (!ft_strncmp(tools->cmds->str[0], "exit", 4))
	{
		free(tools->args);
		free_arr(tools->cmds->str);
		free(tools->cmds);
		exit (0);
	}
	fork_value = fork();
	if (fork_value < 0)
	{
		free(tools->args);
		ft_putendl_fd("fail to fork", 2);
		g_global.exit_status = 1;
	}
	if (fork_value == 0)
	{
		if (!access(tools->cmds->str[0], F_OK))
			execve(tools->cmds->str[0], tools->cmds->str, tools->envi);
		i = 0;
		while (tools->paths[i])
		{
			tmp = ft_strjoin(tools->paths[i], tools->cmds->str[0]);
			if (!access(tmp, F_OK))
				execve(tmp, tools->cmds->str, tools->envi);
			free (tmp);
			i++;
		}
		ft_print_err("command not found : ", tools->args);
		exit (0);
	}
	waitpid(fork_value, &status, 0);
	free_arr(tools->cmds->str);
	free (tools->args);
}

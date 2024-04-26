/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:49:35 by npiyapan          #+#    #+#             */
/*   Updated: 2024/04/26 12:58:20 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#define READLINE_MSG	"\033[1;36mminishell\033[34m$ \033[0m"

void	init_cmd(t_tools *tools)
{
	char	**str;
	int		arg_size;
	t_cmds	*cmd_tmp;

	arg_size = ft_strlen(tools->args);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		print_error("Fail to calloc in init_cmd", 2);
	cmd_tmp->str[0] = ft_strdup(tools->args);
	cmd_tmp->str[1] = 0;
	cmd_tmp->str[2] = 0;
	cmd_tmp->next = NULL;
	cmd_tmp->prev = NULL;
	free (tools->args);
	tools->cmds = cmd_tmp;
}

void	my_loop(t_tools *tools)
{
	char	*tmp;
	int		fork_value;
	int		status;
	int		i;

	tools->args = readline(READLINE_MSG);
	tmp = ft_strtrim(tools->args, " ");
	free (tools->args);
	tools->args = ft_strdup(tmp);
	free (tmp);
	if (!tools->args)
	{
		free (tools->args);
		ft_putendl_fd("fail from strdup in my_loop", 1);
		g_global.exit_status = 1;
		return ;
	}
	add_history(tools->args);
	init_cmd(tools);
	// printf("cmd = %s\n", tools->cmds->str[0]);
	if (!ft_strncmp(tools->cmds->str[0], "exit", 4))
	{
		free(tools->cmds->str[0]);
		exit (0);
	}
	fork_value = fork();
	if (fork_value < 0)
	{
		ft_putendl_fd("fail to fork", 2);
		g_global.exit_status = 1;
	}
	if (fork_value == 0)
	{
		if (!access(tools->cmds->str[0], F_OK))
			execve(tools->cmds->str[0], tools->cmds->str, tools->envi);
		i = 0;
		while (tools->envi[i])
		{
			tmp = ft_strjoin(tools->paths[i], tools->cmds->str[0]);
			if (!access(tmp, F_OK))
				execve(tmp, tools->cmds->str, tools->envi);
			free (tmp);
			i++;
		}
	}
	waitpid(fork_value, &status, 0);
	free(tools->cmds->str[0]);
	// 
}

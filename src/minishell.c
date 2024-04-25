/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:21:54 by npiyapan          #+#    #+#             */
/*   Updated: 2024/04/25 16:36:44 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_global	g_global;

// static void	action(int sig, siginfo_t *info, void *context)
// {
// 	(void)context;
// 	(void)info;
// 	if (sig == SIGINT)
// 	{
// 		rl_on_new_line();
// 		printf("\n");
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// 	else if (sig == SIGQUIT)
// 	{
// 		printf("control + '\\' was pressed\n");
// 		g_global.exit_status = 1;
// 	}
// }

int	main(int argc, char **argv, char **env)
{
	t_tools	tools;

	if (argc != 1 || argv[1])
	{
		ft_putendl_fd("no need argument", 2);
		exit (1);
	}
	g_global.exit_status = 0;
	tools.envi = 0;
	tools.pwd = 0;
	tools.oldpwd = 0;
	tools.paths = 0;
	tools.envi = ft_dup_arr(env);
	tools.cmds = NULL;
	if (!tools.envi)
		print_error("failed to dup env", 1);
	if (!find_pwd(&tools))
		print_error("failed to find pwd", 1);
	if (!find_path(&tools))
		print_error("failed to find path", 1);
	// init_signal();
	// struct sigaction	sa;

	// sa.sa_sigaction = action;
	// sa.sa_flags = SA_SIGINFO;
	// sigaction(SIGINT, &sa, 0);
	// sigaction(SIGQUIT, &sa, 0);
	while (!g_global.exit_status)
		my_loop(&tools);
	free_arr(tools.envi);
	if (tools.pwd)
		free(tools.pwd);
	if (tools.oldpwd)
		free(tools.oldpwd);
	if (tools.paths)
		free_arr(tools.paths);
	if (tools.cmds)
		free(tools.cmds);
	return (0);
}

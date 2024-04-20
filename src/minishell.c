/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:21:54 by npiyapan          #+#    #+#             */
/*   Updated: 2024/04/20 23:54:24 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_tools	tools;
	int		i;

	if (argc != 1 || argv[1])
	{
		ft_putendl_fd("no need argument", 2);
		exit (1);
	}
	tools.envi = 0;
	tools.pwd = 0;
	tools.oldpwd = 0;
	tools.paths = 0;
	tools.envi = ft_dup_arr(env);
	if (!tools.envi)
		print_error("failed to dup env", 1);
	if (!find_pwd(&tools))
		print_error("failed to find pwd", 1);
	if (!find_path(&tools))
		print_error("failed to find path", 1);
	init_signal();
	free_arr(tools.envi);
	if (tools.pwd)
		free(tools.pwd);
	if (tools.oldpwd)
		free(tools.oldpwd);
	if (tools.paths)
		free_arr(tools.paths);
	my_loop(&tools);
	return (0);
}

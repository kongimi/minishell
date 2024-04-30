/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:01:46 by npiyapan          #+#    #+#             */
/*   Updated: 2024/04/20 22:27:48 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	print_error(char *str, int a)
{
	ft_putendl_fd(str, 2);
	return (a);
}

int	find_pwd(t_tools *tools)
{
	int		i;
	char	*res1;

	i = -1;
	while (tools->envi[++i])
	{
		res1 = tools->envi[i];
		if (!ft_strncmp(res1, "PWD=", 4))
		{
			tools->pwd = ft_substr(res1, 4, ft_strlen(res1) - 4);
			if (!tools->pwd)
				return (0);
		}
		if (!ft_strncmp(res1, "OLDPWD=", 7))
		{
			tools->oldpwd = ft_substr(res1, 7, ft_strlen(res1) - 7);
			if (!tools->oldpwd)
				return (0);
		}
	}
	return (1);
}

void	add_slash(char **paths)
{
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	while (paths[++i])
	{
		len = ft_strlen(paths[i]) - 1;
		if (ft_strncmp(&paths[i][len], "/", 1) != 0)
		{
			tmp = ft_strjoin(paths[i], "/");
			free (paths[i]);
			paths[i] = tmp;
		}
	}
}

int	find_path(t_tools *tools)
{
	int		i;
	char	*res1;
	char	*tmp_path;

	i = -1;
	while (tools->envi[++i])
	{
		res1 = tools->envi[i];
		if (!ft_strncmp(res1, "PATH=", 5))
		{
			tmp_path = ft_substr(res1, 5, ft_strlen(res1) - 5);
			if (!tmp_path)
				return (0);
			tools->paths = ft_split(tmp_path, ':');
			free (tmp_path);
			if (!tools->paths)
				return (0);
			add_slash(tools->paths);
			return (1);
		}
	}
	return (0);
}

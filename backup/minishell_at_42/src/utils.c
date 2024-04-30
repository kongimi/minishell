/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:51:45 by npiyapan          #+#    #+#             */
/*   Updated: 2024/04/20 13:02:00 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_dup_arr(char **arr)
{
	size_t	i;
	char	**res;

	i = 0;
	while (arr[i])
		i++;
	res = ft_calloc(sizeof(char *), i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		res[i] = ft_strdup(arr[i]);
		if (!res[i])
		{
			free_arr(res);
			ft_putendl_fd("fail to ft_strdup in ft_arr_dup", 2);
			return (NULL);
		}
		i++;
	}
	return (res);
}

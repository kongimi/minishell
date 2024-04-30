/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:29:58 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 13:00:36 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

void	ft_find_remain(t_gnl *gnl)
{
	char	*res;
	char	*next;
	int		i;

	next = NULL;
	res = malloc(gnl->line_last - gnl->nl);
	if (res)
	{
		i = -1;
		while (gnl->nl[++i + 1])
		{
			res[i] = gnl->nl[i + 1];
			if (res[i] == '\n' && next == NULL)
				next = &res[i];
		}
		res[i] = 0;
		gnl->line_last = &res[i];
		free (gnl->line);
		gnl->line = res;
		gnl->nl = next;
		return ;
	}
	free (gnl->line);
	gnl->line = NULL;
	gnl->err = 1;
}

char	*ft_find_line(t_gnl *gnl)
{
	char	*res;
	int		i;

	res = (char *) malloc(gnl->nl - gnl->line + 2);
	if (!res)
	{
		free (gnl->line);
		gnl->line = NULL;
		gnl->err = 1;
		return (NULL);
	}
	i = -1;
	while (++i < (gnl->nl - gnl->line) + 1)
		res[i] = gnl->line[i];
	res[i] = 0;
	if (gnl->line[i] != 0)
		ft_find_remain(gnl);
	else
	{
		gnl->nl = NULL;
		free (gnl->line);
		gnl->line = NULL;
	}
	return (res);
}

char	*ft_get_next_line(t_gnl *gnl)
{
	char	*res;

	if (gnl->nl)
		return (ft_find_line(gnl));
	res = gnl->line;
	gnl->line = NULL;
	gnl->end = 1;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:08:31 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 13:00:48 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

int	ft_join(t_gnl *gnl)
{
	char	*res;
	int		i;
	size_t	len;

	len = gnl->line_last - gnl->line;
	gnl->new_len = len + gnl->read_b;
	res = malloc(sizeof(char) * (gnl->new_len + 1));
	if (!res)
		return (1);
	i = -1;
	while (++i < (int)len)
		res[i] = gnl->line[i];
	i = -1;
	while (++i < (int)gnl->read_b)
	{
		res[len + i] = gnl->buf[i];
		if (res[len + i] == '\n' && gnl->nl == NULL)
			gnl->nl = &res[len + i];
	}
	res[len + i] = 0;
	free (gnl->line);
	gnl->line = res;
	gnl->line_last = &res[len + i];
	return (0);
}

void	ft_find_nl(t_gnl *gnl)
{
	int	i;

	i = -1;
	while (gnl->buf[++i])
	{
		gnl->line[i] = gnl->buf[i];
		if (gnl->line[i] == '\n' && gnl->nl == NULL)
			gnl->nl = &gnl->line[i];
	}
	gnl->line[i] = 0;
	gnl->line_last = &gnl->line[i];
}

void	ft_read(int fd, t_gnl *gnl)
{
	while (!gnl->nl || gnl->err)
	{
		gnl->read_b = read(fd, gnl->buf, BUFFER_SIZE);
		if (gnl->read_b < 1)
			break ;
		gnl->buf[gnl->read_b] = 0;
		if (!gnl->line)
		{
			gnl->line = malloc(gnl->read_b + 1);
			if (!gnl->line)
				gnl->err = 1;
			else
			{
				ft_find_nl(gnl);
				gnl->err = 0;
			}
		}
		else
			gnl->err = ft_join(gnl);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl;

	if ((fd < 0) || BUFFER_SIZE < 1 || gnl.err || gnl.end)
		return (NULL);
	gnl.buf = malloc(BUFFER_SIZE + 1);
	if (!gnl.buf)
	{
		gnl.err = 1;
		return (NULL);
	}
	if (!gnl.nl)
		ft_read(fd, &gnl);
	free (gnl.buf);
	if (gnl.read_b == -1 || gnl.err)
	{
		if (gnl.line)
			free (gnl.line);
		gnl.line = NULL;
	}
	if (!gnl.line)
		return (NULL);
	return (ft_get_next_line(&gnl));
}

// #include <fcntl.h>
// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	fd = open("test", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break;
// 		printf("line = %s\n", line);
// 	}
// }
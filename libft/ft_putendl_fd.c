/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:27:07 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:03 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t			i;
	unsigned char	c;

	if (s == NULL)
		return ;
	if (fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, s + i, 1);
		i++;
	}
	c = '\n';
	write(fd, &c, 1);
}
/*
int	main(void)
{
	char	*s = "1234";
	int	fd;

	fd = open("kong", O_RDWR | O_CREAT);
	ft_putendl_fd(s, fd);
	close (fd);
}*/

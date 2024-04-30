/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:28:01 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:13 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

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
}
/*
int	main(void)
{
	char	*s = "ABCD";
	int	fd;
	char	*res;

	fd = open("kong", O_RDWR, O_CREAT);
	ft_putstr_fd(s, fd);
	printf("read = %zu\n", read(fd, res, 4));
	printf("res = %s\n", res);
	close (fd);
}*/

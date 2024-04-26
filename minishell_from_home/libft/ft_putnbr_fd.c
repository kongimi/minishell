/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:27:36 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:07 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long			mm;
	unsigned char	c;

	if (fd < 0)
		return ;
	mm = n;
	if (mm < 0)
	{
		c = '-';
		write(fd, &c, 1);
		mm = mm * (-1);
	}
	if (mm < 10)
	{
		c = mm + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(mm / 10, fd);
		ft_putnbr_fd(mm % 10, fd);
	}
}
/*
int	main(void)
{
	int	fd;

	fd = open("kong", O_RDWR | O_CREAT);
	ft_putstr_fd("AAAAAAAA", fd);
	close (fd);
	fd = open("kong", O_RDWR | O_CREAT);
	ft_putnbr_fd(9, fd);
	close (fd);
	fd = open("kong", O_RDWR | O_CREAT);
	ft_putnbr_fd(12, fd);
	close (fd);
	fd = open("kong", O_RDWR | O_CREAT);
	ft_putnbr_fd(-2147483648, fd);
	close (fd);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:26:00 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:51:03 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = b;
	c = (unsigned char)c;
	while (i < len)
		ptr[i++] = c;
	return (b);
}
/*
int	main(void)
{
	char	s[20];

	ft_memset(s, 'a', 20);
	printf("%s\n", s);
}*/
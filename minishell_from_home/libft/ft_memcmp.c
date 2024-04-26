/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:24:31 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:50:49 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_a;
	unsigned char	*s2_a;
	size_t			i;

	s1_a = (unsigned char *)s1;
	s2_a = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_a[i] != s2_a[i])
			return (s1_a[i] - s2_a[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	a[5] = {0, 1, 2, 3, 4};
	char	b[5] = {0, 1, 2};

	printf("%d\n", ft_memcmp(a, b, 2));
	printf("%d\n", ft_memcmp(a, b, 4));
	printf("%d\n", ft_memcmp(b, a, 4));
}*/

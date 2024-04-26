/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:33:12 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:52 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_a;
	unsigned char	*s2_a;

	s1_a = (unsigned char *)s1;
	s2_a = (unsigned char *)s2;
	i = 0;
	while ((s1_a[i] || s2_a[i]) && i < n)
	{
		if (s1_a[i] != s2_a[i])
		{
			if ((s1_a[i] - s2_a[i]) > 0)
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	a[5] = "ABCD";
	char	b[5] = "AB";

	printf("%d\n", ft_strncmp(a, b, 2));
	printf("%d\n", ft_strncmp(a, b, 3));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:32:03 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:41 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src && dst)
		return (0);
	if (dstsize <= 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && ((i + 1) < dstsize))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	a[10] = "TestTest";
	char	b[10] = "bbbbbbbb";

	printf("a = %s\n", a); 
	ft_strlcpy(a, b, 5);
	printf("a after ft_strlcpy = %s\n", a);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:31:38 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:38 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	if (dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (src[i] && ((dst_len + i + 1) < (dstsize)))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}
/*
int	main(void)
{
	char	src[30] = "AAAAA";
	char	dst[30];

	ft_memset(dst, 'B', 2);
	printf("src = %s\n", src);
	printf("dst = %s\n", dst);
	ft_strlcat(dst, src, 5);
	printf("ft_strlcat(dst, src, 5) = %s\n", dst);
}*/

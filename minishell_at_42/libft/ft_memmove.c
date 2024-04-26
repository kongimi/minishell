/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:25:18 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:50:59 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst_2;
	char		*src_2;

	if (!(dst) && !(src))
		return (NULL);
	dst_2 = (char *)dst;
	src_2 = (char *)src;
	if (dst > src)
	{
		i = len;
		while (i-- != 0)
			dst_2[i] = src_2[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst_2[i] = src_2[i];
			i++;
		}
	}
	return (dst);
}

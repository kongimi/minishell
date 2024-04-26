/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:34:00 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:59 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;
	char	*s2;

	s2 = (char *)s;
	slen = ft_strlen(s2);
	c = (unsigned char)c;
	while (slen)
	{
		if (s2[slen] == c)
			return (s2 + slen);
		slen--;
	}
	if (s2[slen] == c)
		return (s2 + slen);
	return (NULL);
}
/*
int	main(void)
{
	char	a[10] = "TestTest";

	printf("%s\n", ft_strrchr(a, 'a'));
	printf("%s\n", ft_strrchr(a, 'T'));
}*/

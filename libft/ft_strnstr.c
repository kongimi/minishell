/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:33:34 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:56 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && !len)
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && (i < len))
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && ((i + j) < len))
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	a[5] = "abcd";
	char	b[5] = "bc";

	printf("%s\n", ft_strnstr(a, b, 2));
	printf("%s\n", ft_strnstr(a, b, 3));
}*/

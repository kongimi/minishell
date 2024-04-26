/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:31:15 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:35 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = ft_calloc(sizeof(char), s1_len + s2_len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcat(res, s1, s1_len + 1);
	ft_strlcat(res, s2, s1_len + s2_len + 1);
	return (res);
}
/*
int	main(void)
{
	char	*a = "1234";
	char	*b = "abcd";
	char	*c;

	c = ft_strjoin(a, b);
	printf("%s\n", c);
}*/

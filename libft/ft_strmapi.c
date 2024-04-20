/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:32:51 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:48 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	res = ft_calloc(sizeof(char), len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}
/*
char	addOne(unsigned int i, char c)
{
	return (i + c);
}

int	main(void)
{
	char	*s;

	s = ft_strmapi("1234", addOne);
	printf("%s\n", s);
	free(s);
}*/

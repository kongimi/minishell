/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:34:30 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 13:00:06 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	check_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*res;
	char	*s1_a;

	if (s1 == 0 || set == 0)
		return (NULL);
	s1_a = (char *)s1;
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && check_set(set, s1_a[begin]))
		begin++;
	while ((end > begin) && check_set(set, s1_a[end - 1]))
		end--;
	res = ft_calloc(sizeof(char), end - begin + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1_a + begin, end - begin +1);
	return (res);
}
/*
int	main(void)
{
	char	*a = "ABCDEFAB";
	char	*b = "AB";
	char	*c;
	char	*d = "t";
	char	*e = "A";

	printf("a = %s\n", a);
	c = ft_strtrim(a, b);
	printf("after trim = %s\n", c);

	c = ft_strtrim(a, d);
	printf("after trim 't' = %s\n", c);
	
	c = ft_strtrim(a, e);
	printf("after trim 'A' = %s\n", c);
}*/

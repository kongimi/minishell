/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:30:12 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/02 11:26:39 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/ft_printf.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	s2 = ft_calloc(sizeof(char), (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
/*
int	 main(void)
{
	char	*a = "ABCDEF";
	char	*b;

	b = ft_strdup(a);
	printf("%s\n", b);
	free (b);
}*/

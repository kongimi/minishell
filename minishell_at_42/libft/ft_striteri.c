/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:30:46 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:28 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}
/*
void	iter(unsigned int i, char * s) {
	*s += i;
}

int	main(void)
{
	char	s[] = "";
	ft_striteri(s, iter);
	printf("s = %s\n", s);

	char	g[] = "0";
	ft_striteri(g, iter);
	printf("g = %s\n", g);

	char	y[] = "000000000";
	ft_striteri(y, iter);
	printf("y = %s\n", y);
}*/

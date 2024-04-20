/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:14:41 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/22 11:43:10 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_atoi(const char *str)
{
	long	res;
	int		i;
	int		mul;

	i = 0;
	res = 0;
	mul = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		mul = -1;
	if ((mul == -1) || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > INT_MAX || res < INT_MIN)
			return (0);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * mul);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi("101"));
	printf("%d\n", ft_atoi("-101"));
	printf("%d\n", ft_atoi("+101"));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:18:43 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:50:03 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

size_t	find_len(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		n = n * (-1);
		len++;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	size_t	i;
	long	mm;

	mm = n;
	len = find_len(mm);
	res = ft_calloc(sizeof(char), len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	if (mm < 0)
		mm = mm * (-1);
	while (i < len)
	{
		res[len - i - 1] = (mm % 10) + '0';
		mm = mm / 10;
		i++;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
/*
int	main(void)
{
	char	*res;

	res = ft_itoa(9);
	printf("9 = %s\n", res);
	res = ft_itoa(19);
	printf("19 = %s\n", res);
	res = ft_itoa(-9);
	printf("-9 = %s\n", res);
	free (res);
	res = ft_itoa(-2147483648);
	printf("-2147483648 = %s\n", res);
	free (res);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:38:31 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/01 12:09:57 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

size_t	ft_findlen_dec(int ptr, int base)
{
	size_t	len;
	int		my_base;

	len = 1;
	if (ptr < 0)
	{
		ptr = ptr * (-1);
		len++;
	}
	my_base = base - 1;
	while (ptr > my_base)
	{
		len++;
		ptr = ptr / base;
	}
	return (len);
}

char	*ft_itoa_dec(int ptr, int base)
{
	t_pf	pf;

	pf.nn = ptr;
	pf.len = ft_findlen_dec(pf.nn, base);
	pf.res = malloc(sizeof(char) * (pf.len + 1));
	if (pf.res == NULL)
		return (NULL);
	if (pf.nn < 0)
		pf.nn = pf.nn * (-1);
	pf.i = 0;
	while (pf.i < pf.len)
	{
		ft_base(&pf, base);
		pf.nn = pf.nn / base;
		pf.i++;
	}
	pf.res[pf.i] = 0;
	if (ptr < 0)
		pf.res[0] = '-';
	return (pf.res);
}

int	ft_writedec(int c)
{
	int		len;
	char	*my_ptr;

	len = 0;
	if (c == INT_MIN)
		my_ptr = "-2147483648";
	else
		my_ptr = ft_itoa_dec(c, 10);
	if (my_ptr == NULL)
		return (-1);
	len += ft_writestr(my_ptr);
	if (c != INT_MIN)
		free (my_ptr);
	return (len);
}

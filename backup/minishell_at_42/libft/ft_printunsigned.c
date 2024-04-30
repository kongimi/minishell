/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:52:18 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 13:01:41 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

size_t	ft_findlen_ui(unsigned int ptr, int base)
{
	size_t			len;
	unsigned int	my_base;

	len = 1;
	my_base = base - 1;
	while (ptr > my_base)
	{
		len++;
		ptr = ptr / base;
	}
	return (len);
}

char	*ft_itoa_ui(unsigned int ptr, int base)
{
	t_pf	pf;

	pf.ui = ptr;
	pf.len = ft_findlen_ui(pf.ui, base);
	pf.res = malloc(sizeof(char) * (pf.len + 1));
	if (pf.res == NULL)
		return (NULL);
	pf.i = 0;
	while (pf.i < pf.len)
	{
		pf.res[pf.len - pf.i - 1] = (pf.ui % base) + '0';
		pf.ui = pf.ui / base;
		pf.i++;
	}
	pf.res[pf.i] = 0;
	return (pf.res);
}

int	ft_writeunsignedi(unsigned int c)
{
	int		len;
	char	*my_ptr;

	len = 0;
	my_ptr = ft_itoa_ui(c, 10);
	if (my_ptr == NULL)
		return (-1);
	len += ft_writestr(my_ptr);
	free(my_ptr);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writehex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:06 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 13:01:46 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char	*ft_itoa_hex(unsigned int ptr, int base, char str)
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
		if ((pf.ui % base) > 9)
		{
			if (str == 'x')
				pf.res[pf.len - pf.i - 1] = (pf.ui % base) + 'a' - 10;
			else
				pf.res[pf.len - pf.i - 1] = (pf.ui % base) + 'A' - 10;
		}
		else
			pf.res[pf.len - pf.i - 1] = (pf.ui % base) + '0';
		pf.ui = pf.ui / base;
		pf.i++;
	}
	pf.res[pf.i] = 0;
	return (pf.res);
}

int	ft_writehex(unsigned int c, char str)
{
	int		len;
	char	*my_ptr;

	len = 0;
	my_ptr = ft_itoa_hex(c, 16, str);
	if (my_ptr == NULL)
		return (-1);
	len += ft_writestr(my_ptr);
	free(my_ptr);
	return (len);
}

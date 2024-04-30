/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:44:25 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 13:01:35 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_write(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_writestr(char *str)
{
	int	i;

	if (str == NULL)
	{
		i = write(1, "(null)", 6);
		if (i == -1)
			return (-1);
		return (i);
	}
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_check(va_list *args, const char *str)
{
	int	len;

	len = 0;
	if (*str == 'c')
		len += ft_write(va_arg(*args, int));
	else if (*str == 's')
		len += ft_writestr(va_arg(*args, char *));
	else if (*str == 'p')
		len += ft_writeptr(va_arg(*args, unsigned long long));
	else if (*str == 'd' || *str == 'i')
		len += ft_writedec(va_arg(*args, int));
	else if (*str == 'u')
		len += ft_writeunsignedi(va_arg(*args, unsigned int));
	else if (*str == 'x' || *str == 'X')
		len += ft_writehex(va_arg(*args, unsigned int), *str);
	else if (*str == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	t_main	tm;

	va_start(tm.args, str);
	tm.i = 0;
	tm.len = 0;
	while (str[tm.i])
	{
		if (str[tm.i] == '%')
		{
			tm.tmp = ft_check(&tm.args, str + tm.i + 1);
			if (tm.tmp == -1)
				return (-1);
			tm.len += tm.tmp;
			tm.i++;
		}
		else
		{
			if (ft_write(str[tm.i]) == -1)
				return (-1);
			tm.len += 1;
		}
		tm.i++;
	}
	va_end(tm.args);
	return (tm.len);
}

// int	main(void)
// {
	// char *a = "1234";
	// printf("len = %i\n",    printf("test %s %c %p %d %i %u %x %X %%\n", 
	// a,'a', a, -1, -256, -2147483647, 2147483647, 2147483647));
	// printf("len = %i\n", ft_printf("test %s %c %p %d %i %u %x %X %%\n", 
	// a, 'a', a, -1, -256, -2147483647, 2147483647, 2147483647));
	// printf(" NULL %s NULL ", NULL);
	//ft_printf(" NULL %s NULL ", NULL);
	//    printf("%c %s %p %d %u %x %X %%\n", 
	//    'a', NULL, NULL, 0, 256, 2147483647, 2147483647);
	// ft_printf("%c %s %p %d %u %x %X %%\n", 
	// 'a', NULL, NULL, 0, 256, 2147483647, 2147483647);
	//    printf("%p\n", (void *)-14523);
	// ft_printf("%p\n", (void *)-14523);
	// ft_printf("\001\002\007\v\010\f\r\n")
	// printf ("%zd\n", write(1, "\002", 1));
// 	   printf("%s\n", "some string with %s hehe");
// 	ft_printf("%s\n", "some string with %s hehe");
// }

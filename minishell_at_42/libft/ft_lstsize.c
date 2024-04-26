/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:23:40 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:50:38 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_lstsize(t_list *st)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	tmp = st;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
/*
void freeList(t_list *head) 
{
	if (head) 
		freeList((t_list *)head->next); 
	free(head);
}

int	main(void)
{
	t_list	*a;
	int	res;

	a = ft_lstnew("a");
	res = ft_lstsize(a);
	printf("res = %d\n", res);
	ft_lstadd_front(&a, ft_lstnew("B"));
	res = ft_lstsize(a);
	printf("res = %d\n", res);
	freeList (a);
}*/
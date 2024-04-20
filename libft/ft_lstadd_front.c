/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:19:53 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/22 12:50:09 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*a = NULL;

	a = ft_lstnew("a");
	ft_lstadd_front(&a, ft_lstnew("B"));
	printf("%s\n", a->content == "B" ? "Y" : "N");
	a = a->next;
	printf("%s\n", a->content == "a" ? "Y" : "N"); 
}*/

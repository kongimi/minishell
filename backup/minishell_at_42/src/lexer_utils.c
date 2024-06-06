/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:43:15 by npiyapan          #+#    #+#             */
/*   Updated: 2024/06/06 13:24:26 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_lexer	*ft_lexernew(char *str, int token)
{
	t_lexer		*new_lexer;
	static int	i;

	new_lexer = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new_lexer)
		return (0);
	new_lexer->str = str;
	new_lexer->token = token;
	new_lexer->i = i++;
	new_lexer->next = NULL;
	new_lexer->prev = NULL;
	return (new_lexer);
}

void	ft_lexeradd_back(t_lexer **lst, t_lexer *new)
{
	t_lexer	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_lexerclear(t_lexer **lst)
{
	t_lexer	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->str)
			free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

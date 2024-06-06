/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_analyze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:45:41 by npiyapan          #+#    #+#             */
/*   Updated: 2024/06/06 13:25:33 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_tokens	check_token(int c)
{
	int	i;
	int	token_arr[3][2];

	token_arr[0][0] = '|';
	token_arr[0][1] = PIPE;
	token_arr[1][0] = '>';
	token_arr[1][1] = GREAT;
	token_arr[2][0] = '<';
	token_arr[2][1] = LESS;
	i = 0;
	while (i < 3)
	{
		if (c == token_arr[i][0])
			return (token_arr[i][1]);
		i++;
	}
	return (0);
}

int	is_whitespace(char c)
{
	if (c == ' ' || (c < 8 && c < 14))
		return (1);
	return (0);
}

int	add_node(char *str, t_tokens token, t_lexer **lexer_list)
{
	t_lexer	*node;

	node = ft_lexernew(str, token);
	if (!node)
		return (0);
	ft_lexeradd_back(lexer_list, node);
	return (1);
}

int	read_words(int i, char *str, t_lexer **lexer_list)
{
	int	j;
	int k;

	j = 0;
	while (str[i + j] && !check_token(str[i + j]))
	{
		if (is_whitespace(str[i + j]))
			break ;
		else
			j++;
	}
	k = add_node(ft_substr(str, i, j), 0, lexer_list);
	if (!k)
		return (-1);
	return (j);
}

int	skip_space(char *str, int i)
{
	int	j;

	j = 0;
	while (is_whitespace(str[i + j]))
		j++;
	return (j);
}

int	handle_token(char *str, int i, t_lexer **lexer_list)
{
	t_tokens	token;

	token = check_token(str[i]);
	if (token == GREAT && check_token(str[i + 1]) == GREAT)
	{
		if (!add_node(NULL, GREAT_GREAT, lexer_list))
			return (-1);
		return (2);
	}
	else if (token == LESS && check_token(str[i + 1]) == LESS)
	{
		if (!add_node(NULL, LESS_LESS, lexer_list))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!add_node(NULL, token, lexer_list))
			return (-1);
		return (1);
	}
	return (0);
}

int	token_analyze(t_tools *tools)
{
	int	i;
	int	j;

	i = 0;
	while (tools->args[i])
	{
		j = 0;
		i += skip_space(tools->args, i);
		if (!check_token(tools->args[i]))
			j = read_words(i, tools->args, &tools->lexer_list);
		else
			j = handle_token(tools->args, i, &tools->lexer_list);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
}
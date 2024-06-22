/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:30:10 by npiyapan          #+#    #+#             */
/*   Updated: 2024/06/22 11:42:03 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>
#include <string.h>

int	count_args(t_lexer *lexer_list)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lexer_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->i >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	parser_error(int error, t_tools *tools, t_lexer *lexer_list)
{
	ft_lexerclear(&lexer_list);
	ft_error(error, tools);
}

// t_cmds	*ft_cmdsnew(char **str,
// 	int num_redirections, t_lexer *redirections)
t_cmds	*ft_cmdsnew(char **str)
{
	t_cmds	*new_element;

	new_element = (t_cmds *)malloc(sizeof(t_cmds));
	if (!new_element)
		return (0);
	new_element->str = str;
	// new_element->builtin = builtin_arr(str[0]);
	new_element->hd_file_name = NULL;
	// new_element->num_redirections = num_redirections;
	// new_element->redirections = redirections;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

t_cmds	*initialize_cmd(t_parser_tools *parser_tools)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*tmp;

	i = 0;
	arg_size = count_args(parser_tools->lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		parser_error(1, parser_tools->tools, parser_tools->lexer_list);
	tmp = parser_tools->lexer_list;
	while (arg_size > 0)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			ft_lexerdelone(&parser_tools->lexer_list, tmp->i);
			tmp = parser_tools->lexer_list;
		}
		arg_size--;
	}
	return (ft_cmdsnew(str));
}

void	count_pipes(t_lexer *lexer_list, t_tools *tools)
{
	t_lexer	*tmp;

	tmp = lexer_list;
	while (tmp)
	{
		if (tmp->token == PIPE)
			tools->pipes++;
		tmp = tmp->next;
	}
}

void	ft_cmdsclear(t_cmds **lst)
{
	t_cmds		*tmp;
	t_lexer		*redirections_tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		redirections_tmp = (*lst)->redirections;
		ft_lexerclear(&redirections_tmp);
		if ((*lst)->str)
			free_arr((*lst)->str);
		if ((*lst)->hd_file_name)
			free((*lst)->hd_file_name);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	implement_tools(t_tools *tools)
{
	tools->cmds = NULL;
	tools->lexer_list = NULL;
	// tools->reset = false;
	tools->pid = NULL;
	tools->pipes = 0;
	// tools->heredoc = false;
	// g_global.stop_heredoc = 0;
	// g_global.in_cmd = 0;
	// g_global.in_heredoc = 0;
	// parse_envp(tools);
	// init_signals();
	return (1);
}

int	reset_tools(t_tools *tools)
{
	// ft_cmdsclear(tools->cmds);
	free(tools->args);
	if (tools->pid)
		free(tools->pid);
	free_arr(tools->paths);
	implement_tools(tools);
	// tools->reset = true;
	printf("test6\n");
	my_loop(tools);
	printf("test7\n");
	return (1);
}

void	ft_cmds_add_back(t_cmds **lst, t_cmds *new)
{
	t_cmds	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		printf("*lst = NULL\n");
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_parser_tools	init_parser_tools(t_lexer *lexer_list, t_tools *tools)
{
	t_parser_tools	parser_tools;

	parser_tools.lexer_list = lexer_list;
	// parser_tools.redirections = NULL;
	// parser_tools.num_redirections = 0;
	parser_tools.tools = tools;
	return (parser_tools);
}

void	print_cmd(t_tools *tools)
{
	t_tools	*tmp;
	int		i;

	tmp = tools;
	i = 0;
	while (tmp->cmds)
	{
		while (tools->cmds->str[i])
		{
			printf("%s ", tools->cmds->str[i]);
			i++;
		}
		printf("\n");
		tmp->cmds = tmp->cmds->next;
	}
}

int	parser(t_tools *tools)
{
	t_cmds	*node;
	t_parser_tools	parser_tools;

	tools->cmds = NULL;
	count_pipes(tools->lexer_list, tools);

	while (tools->lexer_list)
	{
		if (tools->lexer_list && tools->lexer_list->token == PIPE)
			ft_lexerdelone(&tools->lexer_list, tools->lexer_list->i);
		parser_tools = init_parser_tools(tools->lexer_list, tools);
		node = initialize_cmd(&parser_tools);
		if (!tools->cmds){
			tools->cmds = node;
		}
		else{
			ft_cmds_add_back(&tools->cmds, node);
		}
		// print_cmd(tools);
		tools->lexer_list = parser_tools.lexer_list;
	}
	return (1);
}

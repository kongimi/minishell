/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:30:10 by npiyapan          #+#    #+#             */
/*   Updated: 2024/06/06 11:49:05 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmds	*initialize_cmd(char **str)
{
	t_cmds	*node;

	node = malloc(sizeof(t_cmds));
	if (!node)
		print_error("fail to malloc node", 2);
	node->str = ft_dup_arr(str);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// void	count_pipes(t_lexer *lexer_list, t_tools *tools)
// {
// 	t_lexer	*tmp;

// 	tmp = lexer_list;
// 	while (tmp)
// 	{
// 		if (tmp->token == PIPE)
// 			tools->pipes++;
// 		tmp = tmp->next;
// 	}
// }

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
	// tools->pid = NULL;
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

int	parser(t_tools *tools)
{
	t_cmds	*node;
	t_lexer	*tmp;
	char	**str;
	int		i;
	int		lexer_len;

	tools->cmds = NULL;
	// count_pipes(tools->lexer_list, tools_tmp);
	
	// if (tools->lexer_list->token == PIPE)
	// {
	// 	ft_putendl_fd("minishell: parse error near '|'", STDERR_FILENO);
	// 	ft_lexerclear(&tools->lexer_list);
	// 	reset_tools(tools);
	// 	return (1);
	// }

	
	
	tmp = tools->lexer_list;
	lexer_len = 1;
	while (tmp->next)
	{
		lexer_len++;
		tmp = tmp->next;
	}
	str = malloc(sizeof(t_lexer) * lexer_len + 1);
	i = 0;
	while (tools->lexer_list)
	{
		str[i] = ft_strdup(tools->lexer_list->str);
		i++;
		tmp = tools->lexer_list->next;
		free (tools->lexer_list->str);
		free (tools->lexer_list);
		tools->lexer_list = tmp;
	}
	str[i] = 0;
	node = initialize_cmd(str);
	tools->cmds = &node;
	return (1);
}

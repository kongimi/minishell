/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:49:35 by npiyapan          #+#    #+#             */
/*   Updated: 2024/04/20 23:55:13 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#define READLINE_MSG	"\033[1;36mminishell\033[34m$ \033[0m"

void	my_loop(t_tools *tools)
{
	tools->args = readline(READLINE_MSG);
	my_loop(tools);
}

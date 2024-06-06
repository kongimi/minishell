/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:20:17 by npiyapan          #+#    #+#             */
/*   Updated: 2024/05/26 17:06:45 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>

# include "../include/parser.h"

extern t_global	g_global;

void	my_loop(t_tools *tools);
int		token_analyze(t_tools *tools);
int		parser(t_tools *tools);
t_lexer	*ft_lexernew(char *str, int token);
void	ft_lexeradd_back(t_lexer **lst, t_lexer *new);
void	init_cmd(t_tools *tools);
void	ft_lexerclear(t_lexer **lst);

#endif
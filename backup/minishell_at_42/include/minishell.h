/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:20:17 by npiyapan          #+#    #+#             */
/*   Updated: 2024/06/08 13:44:01 by npiyapan         ###   ########.fr       */
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
# include <sys/wait.h>

# include "../include/parser.h"

# define READLINE_MSG	"\033[1;36mminishell\033[34m$ \033[0m"

extern t_global	g_global;

void	my_loop(t_tools *tools);
int		token_analyze(t_tools *tools);
int		parser(t_tools *tools);
t_lexer	*ft_lexernew(char *str, int token);
void	ft_lexeradd_back(t_lexer **lst, t_lexer *new);
void	init_cmd(t_tools *tools);
void	ft_lexerclear(t_lexer **lst);
void	ft_lexerdelone(t_lexer **lst, int key);
int		reset_tools(t_tools *tools);
int		ft_error(int error, t_tools *tools);
#endif
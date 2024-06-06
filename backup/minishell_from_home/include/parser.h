/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:34:51 by npiyapan          #+#    #+#             */
/*   Updated: 2024/05/26 23:16:47 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_tools
{
	char					*args;
	char					**envi;
	char					**paths;
	char					*pwd;
	char					*oldpwd;
	struct s_cmds			*cmds;
	t_lexer					*lexer_list;
	int						pipes;
	int						*pid;
	bool					reset;
	bool					heredoc;
}	t_tools;

typedef struct s_cmds
{
	char			**str;
	struct s_cmds	*next;
	struct s_cmds	*prev;
	t_lexer			*redirections;
	char			*hd_file_name;
}	t_cmds;

typedef struct s_global
{
	int	exit_status;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

void	free_arr(char **arr);
void	init_signal(void);

int		find_pwd(t_tools *tools);
int		find_path(t_tools *tools);
int		print_error(char *str, int a);

char	**ft_dup_arr(char **arr);

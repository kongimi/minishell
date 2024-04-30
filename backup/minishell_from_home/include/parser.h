/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:34:51 by npiyapan          #+#    #+#             */
/*   Updated: 2024/04/26 11:08:08 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_tools
{
	char					*args;
	char					**envi;
	char					**paths;
	char					*pwd;
	char					*oldpwd;
	struct s_cmds			*cmds;	
}	t_tools;

typedef struct s_cmds
{
	char			**str;
	struct s_cmds	*next;
	struct s_cmds	*prev;
}	t_cmds;

typedef struct s_global
{
	int	exit_status;
}	t_global;

void	free_arr(char **arr);
void	init_signal(void);

int		find_pwd(t_tools *tools);
int		find_path(t_tools *tools);
int		print_error(char *str, int a);

char	**ft_dup_arr(char **arr);

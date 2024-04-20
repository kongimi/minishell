/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:34:51 by npiyapan          #+#    #+#             */
/*   Updated: 2024/04/20 22:55:36 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_tools
{
	char					*args;
	char					**envi;
	char					**paths;
	char					*pwd;
	char					*oldpwd;
}	t_tools;

void	free_arr(char **arr);
void	init_signal(void);

int		find_pwd(t_tools *tools);
int		find_path(t_tools *tools);
int		print_error(char *str, int a);

char	**ft_dup_arr(char **arr);

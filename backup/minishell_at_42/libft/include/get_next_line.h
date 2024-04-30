/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:09:40 by npiyapan          #+#    #+#             */
/*   Updated: 2023/10/23 22:26:18 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	char	*line;
	char	*buf;
	char	*nl;
	char	*line_last;
	char	*remain;
	int		err;
	int		end;
	int		read_b;
	size_t	new_len;
}			t_gnl;

char	*get_next_line(int fd);
void	ft_read(int fd, t_gnl *gnl);
void	ft_find_nl(t_gnl *gnl);
int		ft_join(t_gnl *gnl);
void	ft_find_remain(t_gnl *gnl);
char	*ft_find_line(t_gnl *gnl);
char	*ft_get_next_line(t_gnl *gnl);

#endif
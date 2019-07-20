/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:57:13 by bglinda           #+#    #+#             */
/*   Updated: 2019/07/19 16:42:20 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;
typedef struct	s_tetris
{
	char		**pos;
	int			width;
	int			height;
	char		letter;
}				t_tetris;
typedef struct	s_dot
{
	int			x;
	int			y;
}				t_dot;

typedef struct	s_sq
{
	int count;
}				t_sq;
t_tetris		*create_tetris(char **pos, int width, int height, char letter);
t_map			*create_map(int size);
void			print_map(t_map *map);
t_dot			*create_dot(int x, int y);
int				def_width(char *str);
int				def_height(char *str);
int				def_min_y(char *str);
int				def_min_x(char *str);
t_tetris		*cut_tetris(char *str, char letter);
t_list			*reader(int fd, t_sq *sq);
t_map			*solver(t_list *list, t_sq *sq);
int				back(t_map *map, t_list *list);
int				good(t_tetris *tetris, t_map *map, int x, int y);
void			free_map(t_map *map);
void			set_letter(t_tetris *tetris, t_map *map, t_dot *dot, char let);
int				ft_sqrt(int num);
t_list			*free_list(t_list *list);
void			free_map(t_map *map);
int				points_and_sq(char *str);
int				carry(char *str);
int				valid(char *str, t_sq *sq);
void			errror(void);

#endif

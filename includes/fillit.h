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
# define T1 0xC440
# define T2 0x8980
# define T3 0xC880
# define T4 0x88C0
# define T5 0xE200
# define T6 0xB800
# define T7 0x8E00
# define T8 0xE800
# define T9 0x8C40
# define T10 0x9900
# define T11 0xC600
# define T12 0xD800
# define T13 0x8888
# define T14 0xF000
# define T15 0xCC00
# define T16 0xE400
# define T17 0x9C00
# define T18 0x8C80
# define T19 0x9880
# define BD3 0x780
# define BD5 0x7800
# define BD6 0x78
# define BD7 0x3C00
# define BD8 0x3C0
# define BD9 0x3C

typedef struct	s_node
{
	int			fis[26];
	char		*mas;
	int			fdr;
	int			t3_c[2];
	int			i;
	int			fig;
	int			j;
	int			i_g;
	int			sq;
	int			count_doc;
	int			count_sn;
	int			trig_one;
}				t_node;
void			all_tonull(t_node *list);
void			shmon_symb(t_node *list, int fd);
void			valid_dlc(t_node *list);
void			fresh(t_node *list);
void			start_valid(int fd, t_node *list);
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
t_tetris		*create_tetris(char **pos, int width, int height, char letter);
t_map			*create_map(int size);
void			print_map(t_map *map);
t_dot			*create_dot(int x, int y);
int				def_width(char *str);
int				def_height(char *str);
int				def_min_y(char *str);
int				def_min_x(char *str);
t_tetris		*cut_tetris(char *str, char letter);
t_list			*reader(int fd);
t_map			*solver(t_list *list);
int				back(t_map *map, t_list *list);
int				good(t_tetris *tetris, t_map *map, int x, int y);
void			free_map(t_map *map);
void			set_letter(t_tetris *tetris, t_map *map, t_dot *dot, char let);
int				ft_sqrt(int num);
t_list			*free_list(t_list *list);
void			free_map(t_map *map);

int	dots_and_sharps(char *str);
int	additional(char *str);
int	validation(char *str);
void	fault(void);
int		read_file(int fd);

#endif

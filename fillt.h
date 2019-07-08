/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:57:13 by bglinda           #+#    #+#             */
/*   Updated: 2019/07/02 20:57:13 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLT_H
#define FILLIT_FILLT_H

#include <fcntl.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
    int			size;
    char		**array;
}				t_map;

typedef struct	s_tetris
{
    char		**pos;
    int         width;
    int         height;
    char		letter;
    int         min_x;
    int         min_y;
}				t_tetris;

typedef struct  s_dot
{
	int x;
	int y;
}			    t_dot;

t_tetris *create_tetris(char **pos, int width, int height, char letter);
t_map *create_map(int size);
void print_map(t_map *map);
t_dot *create_dot(int x, int y);
int def_width(char *str);
int def_height(char *str);
int def_min_y(char *str);
int def_min_x(char *str);
t_tetris *cut_tetris(char *str, char letter);
t_list reader(int fd);

#endif

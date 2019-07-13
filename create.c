/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:33:51 by bglinda           #+#    #+#             */
/*   Updated: 2019/07/06 15:33:54 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillt.h"

t_tetris *create_tetris(char **pos, int width, int height, char letter)
{
    t_tetris *tetris;

    tetris = ft_memalloc(sizeof(t_tetris));
    tetris->pos = pos;
    tetris->height = height;
    tetris->width = width;
    tetris->letter = letter;
    return (tetris);
}

t_map *create_map(int size)
{
    t_map *map;
    int i;
    int j;

    j = 0;
    map = ft_memalloc(sizeof(t_map));
    map->size = size;
    map->array = (char **)ft_memalloc(sizeof(char *) * size);
    while(j < size)
    {

        map->array[j] = ft_strnew(size);
        i = 0;
        while(i < size)
        {
            map->array[j][i] = '.';
            i++;
        }
        j++;
    }
    return (map);
}

void print_map(t_map *map)
{
    int j;

    j = 0;
    while(j < map->size)
    {
        ft_putstr(map->array[j]);
        //printf("%s\n",map->array[j]);
        ft_putchar('\n');
        j++;

    }
}

t_dot *create_dot(int x, int y)
{
    t_dot *dot;

    dot = ft_memalloc(sizeof(t_dot));
    dot->x = x;
    dot->y = y;
    return (dot);
}

void free_map(t_map *map)
{
    int i;

    i = 0;
    while(i < map->size)
    {
        ft_memdel((void **)&(map->array[i]));
        i++;
    }
    ft_memdel((void **)&(map->array));
    ft_memdel((void **)&(map));
}

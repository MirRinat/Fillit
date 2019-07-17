/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:47:01 by bglinda           #+#    #+#             */
/*   Updated: 2019/07/08 20:47:03 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				ft_lstcount(t_list *list)
{
	int			i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void			set_letter(t_tetris *tetris, t_map *map, t_dot *dot, char let)
{
	int			i;
	int			j;

	i = 0;
	while (i < tetris->width)
	{
		j = 0;
		while (j < tetris->height)
		{
			if (tetris->pos[j][i] == '#')
				map->array[dot->y + j][dot->x + i] = let;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&dot);
}

int				good(t_tetris *tetris, t_map *map, int x, int y)
{
	int			i;
	int			j;

	i = 0;
	while (i < tetris->width)
	{
		j = 0;
		while (j < tetris->height)
		{
			if (tetris->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_letter(tetris, map, create_dot(x, y), tetris->letter);
	return (1);
}

int				back(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_tetris	*tetris;

	if (list == NULL)
		return (1);
	y = 0;
	tetris = (t_tetris *)(list->content);
	while (y < map->size - tetris->height + 1)
	{
		x = 0;
		while (x < map->size - tetris->width + 1)
		{
			if (good(tetris, map, x, y))
			{
				if (back(map, list->next))
					return (1);
				else
					set_letter(tetris, map, create_dot(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map			*solver(t_list *list, t_node *list2)
{
	t_map		*map;
	int			size;

	if (list2->sq == 10)
		size = 8;
	size = ft_sqrt(ft_lstcount(list) * 4);
	map = create_map(size);
	while (!back(map, list))
	{
		size++;
		free_map(map);
		map = create_map(size);
	}
	return (map);
}

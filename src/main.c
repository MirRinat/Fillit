/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:56:32 by bglinda           #+#    #+#             */
/*   Updated: 2019/07/05 14:35:59 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			ft_lstrev(t_list **alst)
{
	t_list		*prev;
	t_list		*cur;
	t_list		*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

t_tetris		*cut_tetris(char *str, char letter)
{
	char		**pos;
	int			j;
	int			width;
	int			height;
	t_tetris	*tetris;

	width = def_width(str);
	height = def_height(str);
	pos = ft_memalloc(sizeof(char *) * (height));
	j = 0;
	while (j < height)
	{
		pos[j] = ft_strnew(width);
		ft_strncpy(pos[j], str + (def_min_x(str)) + (j + def_min_y(str)) * 5,
				width);
		j++;
	}
	tetris = create_tetris(pos, width, height, letter);
	return (tetris);
}

t_list			*reader(int fd)
{
	t_list		*list;
	char		*buffer;
	int			ret;
	t_tetris	*tetris;
	char		letter;

	letter = 'A';
	list = NULL;
	buffer = ft_strnew(21);
	while ((ret = read(fd, buffer, 21)) >= 20)
	{
		if ((tetris = cut_tetris(buffer, letter++)) == NULL)
		{
			ft_memdel((void **)&buffer);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_tetris)));
		ft_memdel((void **)&tetris);
	}
	ft_memdel((void **)&buffer);
	ft_lstrev(&list);
	return (list);
}

int				main(int argc, char **argv)
{
	t_list		*list;
	t_map		*map;
	t_node		*list2;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	list2 = (t_node *)malloc(sizeof(t_node));
	start_valid(open(argv[1], O_RDONLY), list2);
	if (list2->fis[1] <= 0 || list2->i_g > 0 ||
					(list = reader(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	map = solver(list, list2);
	ft_memdel((void **)&list2);
	print_map(map);
	free_map(map);
	free_list(list);
	return (0);
}

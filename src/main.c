/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:56:32 by bglinda           #+#    #+#             */
/*   Updated: 2019/07/19 17:03:54 by bantario         ###   ########.fr       */
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

void			del_buf(char *buffer)
{
	if (buffer[20] != '\0')
		errror();
	ft_memdel((void **)&buffer);
}

t_list			*reader(int fd, t_sq *sq)
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
		buffer[ret] = '\0';
		if (!(valid(buffer, sq)) ||
					(tetris = cut_tetris(buffer, letter++)) == NULL)
		{
			ft_memdel((void **)&buffer);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_tetris)));
		ft_memdel((void **)&tetris);
	}
	del_buf(buffer);
	ft_lstrev(&list);
	return (list);
}

int				main(int argc, char **argv)
{
	t_list		*list;
	t_map		*map;
	t_sq		*sq;
	int			fd;

	sq = (t_sq *)malloc(sizeof(t_sq));
	sq->count = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if ((list = reader(fd, sq)) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	map = solver(list, sq);
	print_map(map);
	free(sq);
	free_map(map);
	free_list(list);
	return (0);
}

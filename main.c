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

#include "fillt.h"


t_tetris *cut_tetris(char *str, char letter)
{
    char **pos;
    int j;
    int width;
    int height;
    int min_x;
    int min_y;
    t_tetris *tetris;

    width = def_width(str);
    height = def_height(str);
    min_x = def_min_x(str);
    min_y = def_min_y(str);
    pos = ft_memalloc(sizeof(char *) * height + 1);
    j = 0;
    while(j < def_height(str))
    {
        pos[j] = ft_strnew(def_width(str));
        ft_strncpy(pos[j],str + tetris->min_x + (j + tetris->min_y) * 5, def_width(str));
        j++;
    }
    tetris = create_tetris(pos,width,height, letter);
    return (tetris);
}

t_list reader(int fd)
{
    t_list *list;
    t_list *new_fig;
    char *buffer;
    int ret;
    t_tetris *tetris;
    char letter = 'A';

    letter = 'A';
    list = NULL;
    new_fig = NULL;
    buffer = ft_strnew(21);
    while((ret = read(fd, buffer, 21)) >= 20)
    {
        tetris = cut_tetris(buffer,letter);
        new_fig = ft_lstnew(tetris, sizeof(t_tetris));
        ft_lstadd(&list,new_fig);
        letter++;
    }
    return (*list);
}



int main(int argc, char **argv)
{
    int fd;
    int ret;
    char *buf;
    t_map map;
    t_list *list;
    t_tetris *teee;

    //map = create_map(4);
    //print_map(map);
    fd = open(argv[1], O_RDONLY);
    ret = read(fd, buf, 21);
    teee= cut_tetris(buf,'A');
    printf("%s",*teee->pos);
    //list = reader(fd);

}


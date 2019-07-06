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

    width = def_width(str);
    height = def_height(str);
    pos = ft_memalloc(sizeof(char *) * height + 1);
    j = 0;
    def_min(str,tetris);
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
    t_list *figure;
    char *buffer;
    int ret;
    t_tetris *tetris;

    ret = read(fd, buf, 21);
    tetris = cut_tetr(buffer,)
    ft_lstnew()

    ft_lstadd(&figure, create_tetris(**pos,width,height,letter) )
}





int main(int argc, char *argv)
{
    int fd;
    int ret;
    char *buf;

    fd = open(argv[1], O_RDONLY)
    ret = read(fd,buf,21);

}


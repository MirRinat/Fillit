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

void		free_tetris(t_tetris *tetri)
{
    int y;

    y = 0;
    while (y < tetri->height)
    {
        ft_memdel((void **)(&(tetri->pos[y])));
        y++;
    }
    ft_memdel((void **)(&(tetri->pos)));
    ft_memdel((void **)&tetri);
}

t_list		*free_list(t_list *list)
{
    t_tetris	*tetris;
    t_list	*next;

    while (list)
    {
        tetris = (t_tetris *)list->content;
        next = list->next;
        free_tetris(tetris);
        ft_memdel((void **)&list);
        list = next;
    }
    return (NULL);
}

void		ft_lstrev(t_list **alst)
{
    t_list	*prev;
    t_list	*cur;
    t_list	*next;

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

    pos = ft_memalloc(sizeof(char *) * (height));
    j = 0;
    while(j < height)
    {
        pos[j] = ft_strnew(width);
        ft_strncpy(pos[j],str + (min_x) + (j + min_y) * 5, width);
        printf("%s\n",pos[j]);

        j++;

    }
  // printf("width = %d\nheight = %d\nminy = %d\nminx = %d\n",width,height,min_y,min_x);
    printf("\n");
    tetris = create_tetris(pos, width, height, letter);

    printf("cut_ done\n");
    return (tetris);
}

t_list *reader(int fd)
{
    t_list *list;
    char *buffer;
    int ret;
    t_tetris *tetris;
    char letter;

    letter = 'A';
    list = NULL;
    //new_fig = NULL;
    buffer = ft_strnew(21);
   // buffer = "##..\n#...\n#...\n....\n\n";


   // while((ret = read(fd, buffer, 21)) >= 20)
 //  while(get_next_line(1,buffer) >= 20)
    while((ret = read(fd, buffer, 21)) >= 20)
    {
       if((tetris = cut_tetris(buffer,letter++)) == NULL)
       {
            ft_memdel((void **)&buffer);
            return (free_list(list));
       }
     ft_lstadd(&list,ft_lstnew(tetris, sizeof(t_tetris)));
        printf("add done\n");
    ft_memdel((void **)&tetris);
        printf("del tet done\n");
    }
     ft_memdel((void **)&buffer);
    printf("del buf done\n");
    ft_lstrev(&list);
    printf("reverse done\n");
    printf("reader done\n");
    return (list);
}


int main(int argc, char **argv)
{
    int fd;
    t_list *list;
    t_map *map;


    fd = open(argv[1], O_RDONLY);
    list = reader(fd);
    map = solver(list);
    print_map(map);
    free_map(map);
    free_list(list);

    return (0);
}

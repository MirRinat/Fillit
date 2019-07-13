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

void print_list(t_list *list)
{

    while(list != NULL)
    {
        printf("%s\n",(char *)&(list->content));
        list = list->next;
    }
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
        ft_strncpy(pos[j],str + min_x + (j + min_y) * 5, width);
        printf("%s\n",pos[j]);

        j++;

    }
    printf("width = %d\nheight = %d\nminy = %d\nminx = %d\n",width,height,min_y,min_x);
    printf("\n");
    tetris = create_tetris(pos,width,height,letter);
    return (tetris);
}

t_list *reader(int fd)
{
    t_list *list;
    //t_list *new_fig;
    char *buffer;
    int ret;
    t_tetris *tetris;
    char letter;

    letter = 'A';
    list = NULL;
    //new_fig = NULL;
    buffer = ft_strnew(21);
    while((ret = read(fd, buffer, 21)) >= 20)
    {
        if((tetris = cut_tetris(buffer,letter++)) == NULL)
        {
            ft_memdel((void **)&buffer);
            return (free_list(list));
        }
        //ft_lstnew(tetris, sizeof(t_tetris));
        ft_lstadd(&list,ft_lstnew(tetris, sizeof(t_tetris)));
        //letter++;
        ft_memdel((void **)&tetris);
        //letter++;
    }
    printf("hete\n");
    ft_memdel((void **)&buffer);
    //print_list(list);
    ft_lstrev(&list);
    return (list);
}



/*int main(int argc, char **argv)
{
    int fd;
    int ret;
    char *buf;
    //t_map map;
    //t_list *list;
    //t_tetris *teee;

    //map = create_map(4);
    //print_map(map);
   // fd = open("a.txt", O_RDONLY);
   // printf("%d\n",fd);
   // printf("%d\n",ret = read(fd, buf, 21));
   // printf("%s\n",buf);
    buf = "..##\n...#\n...#\n....\n\n";
    cut_tetris(buf,'A');
   printf("h = %d\n",def_height("..##\n...#\n...#\n....\n\n"));
    printf("w = %d\n",def_width("..##\n...#\n...#\n....\n\n"));
    printf("mx = %d\n",def_min_x("..##\n...#\n...#\n....\n\n"));
    printf("my = %d\n",def_min_y("..##\n...#\n...#\n....\n\n"));
    //teee= cut_tetris(buf,'A');
    //printf("%s",teee->pos[0]);
    //list = reader(fd);
    return (0);
}*/

int main(int argc, char **argv)
{
    int fd;
    t_list *list;
    t_map *map;

    printf("here\n");
    fd = open(argv[1], O_RDONLY);
    printf("here1\n");
    list = reader(fd);
    //print_list(list);
    printf("here2\n");
    map = solver(list);
  //  printf("here3\n");
    print_map(map);
    printf("here3\n");
    free_map(map);
    printf("here3\n");
    free_list(list);
    printf("here3\n");
    return (0);
}

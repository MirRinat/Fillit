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

/*void print_list(t_list *list)
{

    while(list != NULL)
    {
        printf("%s\n",(char *)&(list->content));
        list = list->next;
    }
}*/
void	min_max(char *str, t_dot *min, t_dot *max)
{
    int i;

    i = 0;
    while (i < 20)
    {
        if (str[i] == '#')
        {
            if (i / 5 < min->y)
                min->y = i / 5;
            if (i / 5 > max->y)
                max->y = i / 5;
            if (i % 5 < min->x)
                min->x = i % 5;
            if (i % 5 > max->x)
                max->x = i % 5;
        }
        i++;
    }
}


t_tetris *cut_tetris(char *str, char letter)
{
    char **pos;
    int j;
    //int width;
    //int height;
   // int min_x;
   // int min_y;
   t_dot *mi;
   t_dot *max;
    t_tetris *tetris;

   // width = def_width(str);
   // height = def_height(str);
  //  min_x = def_min_x(str);
   // min_y = def_min_y(str);
   mi = create_dot(3,3);
   max = create_dot(0,0);
    min_max(str, mi, max);
    pos = ft_memalloc(sizeof(char *) * (max->y - mi->y + 1));
    j = 0;
    while(j < max->y - mi->y + 1)
    {
        pos[j] = ft_strnew(max->x - mi->x + 1);
        ft_strncpy(pos[j],str + (mi->x) + (j + mi->y) * 5, max->x - mi->x + 1);
        printf("%s\n",pos[j]);

        j++;

    }
    //printf("width = %d\nheight = %d\nminy = %d\nminx = %d\n",width,height,min_y,min_x);
    printf("\n");
    tetris = create_tetris(pos, max->x - mi->x + 1, max->y - mi->y + 1, letter);
    ft_memdel((void **)&mi);
    ft_memdel((void **)&max);
    return (tetris);
}

t_list *reader(char *buffer)
{
    t_list *list;
    //char *buffer;
   // int ret;
    t_tetris *tetris;
    char letter;

    letter = 'A';
    list = NULL;
    //new_fig = NULL;
//    buffer = ft_strnew(21);
   // buffer = "##..\n#...\n#...\n....\n\n";


    // while((ret = read(fd, buffer, 21)) >= 20)
   // {
        tetris = cut_tetris(buffer,letter++);
//        {
//            ft_memdel((void **)&buffer);
//            return (free_list(list));
//        }
     ft_lstadd(&list,ft_lstnew(tetris, sizeof(t_tetris)));
     //   ft_memdel((void **)&tetris);
//    }
   // ft_memdel((void **)&buffer);
    //if(ret != 0)
     //   return (free_list(list));
    ft_lstrev(&list);
    return (list);
}


int main(int argc, char **argv)
{
    int fd;
    t_list *list;
    t_map *map;


    //fd = open(argv[1], O_RDONLY);
    list = reader("##..\n##..\n....\n....\n\n");
    map = solver(list);
    print_map(map);
   // free_map(map);
    //free_list(list);

    return (0);
}

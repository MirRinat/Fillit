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

#include "fillt.h"

int ft_sqrt(int num)
{
    int a;

    a = 2;
    while(a * a < num)
        a++;
    return (a);
}

int ft_lstcount(t_list *list)
{
    int i;

    i = 0;
    while(list != NULL)
    {
        list = list->next;
        i++;
    }
    return (i);
}

void set_letter(t_tetris *tetris, t_map *map,t_dot *dot, char letter)
{
    int i;
    int j;

    i = 0;
    while(i < tetris->width)
    {
        j = 0;
        while( j < tetris->height)
        {
            if(tetris->pos[j][i] == '#')
                map->array[dot->y+j][dot->x + i] = letter;
            j++;
        }
        i++;
    }
    printf("set_letter done\n");
    ft_memdel((void **)&dot);
}

int good(t_tetris *tetris,t_map *map,int x,int y)
{
    int i;
    int j;

    i = 0;
    printf("good start\n");
    while(i < tetris->width)
    {
        printf("good start ---- \n");
        j = 0;
        while(j < tetris->height)
        {
            printf("good start |  \n");
            if (tetris->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
            {
                printf("norm mesto \n");
                return (0);
            }

            j++;
        }
        i++;
    }
    set_letter(tetris,map,create_dot(x,y),tetris->letter);
    printf("good done\n");
    return (1);

}

int back(t_map *map, t_list *list)
{
    int x;
    int y;
    t_tetris *tetris;

    if(list == NULL)
        return (1);
    y = 0;
    tetris = (t_tetris *)(list->content);
    while(y < map->size - tetris->height + 1)
    {
        printf("bach height start\n");
        x = 0;
        while (x < map->size - tetris->width + 1)
        {
            printf("bach width start\n");
            if (good(tetris,map,x,y))
            {
                printf("back good done\n");
                if (back(map,list->next))
                {
                    printf("back++ good done\n");
                    return (1);
                }
                else
                {
                    set_letter(tetris,map,create_dot(x,y),'.');
                }
            }
               x++;
        }
        y++;
    }
    printf("back map done\n");
    return (0);
}

t_map *solver(t_list *list)
{
    t_map *map;
    int size;

    size = ft_sqrt(ft_lstcount(list) * 4);
    printf("count list = %d\n",ft_lstcount(list));
    printf("size = %d\n",size);
    map = create_map(size);
    printf("create map done\n");
    while (!back(map,list))
    {
        size++;
        free_map(map);
        map = create_map(size);
        printf("create map done size+\n");
    }
    printf("solver done\n");
    return(map);
}


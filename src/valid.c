/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:54:07 by bantario          #+#    #+#             */
/*   Updated: 2019/07/16 18:32:48 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	t3c(t_node *list)
{
	int		i;

	i = 0;
	while (list->mas[i])
	{
		if ((list->mas[i] == '\n' && (list->mas[i + 1] == '\n'
						|| list->mas[i + 1] == '\0')))
			list->t3_c[1]++;
		i++;
	}
}

void	contine(t_node *list)
{
	if ((list->mas[list->i] == '\n' && (list->mas[list->i + 1] == '\n'
					|| list->mas[list->i + 1] == '\0')))
	{
		if (list->t3_c[0] == 16)
			list->t3_c[0] = 0;
		else
		{
			list->i_g++;
			return ;
		}
		if ((list->fig == BD3) || (list->fig == BD5)
				|| (list->fig == BD6)
				|| (list->fig == BD7) || (list->fig == BD8)
				|| (list->fig == BD9))
		{
			list->i_g++;
			return ;
		}
		while (list->fig <= 0xF000)
			list->fig = list->fig << 1;
		if (list->fig >= 0x10000)
			list->fig = list->fig >> 1;
		fresh(list);
	}
}

void	keks(t_node *list)
{
	if ((list->fig ^ T2) == 0 || (list->fig ^ T6) == 0
			|| (list->fig ^ T10) == 0 || (list->fig ^ T12) == 0
			|| (list->fig ^ T17) == 0 || (list->fig ^ T19) == 0)
	{
		list->i_g++;
		return ;
	}
}

void	lstuse(t_node *list)
{
	if (list->mas[list->i] == '#')
	{
		valid_dlc(list);
		list->fig = list->fig | 1;
		list->fig = list->fig << 1;
		list->t3_c[0]++;
	}
	if (list->mas[list->i] == '.')
	{
		valid_dlc(list);
		list->fig = list->fig << 1;
		list->t3_c[0]++;
	}
	contine(list);
}

void	start_valid(int fd, t_node *list)
{
	list->j = 1;
	list->fig = 0;
	list->t3_c[0] = 0;
	list->t3_c[1] = 0;
	list->sq = 0;
	list->i_g = 0;
	list->mas = ft_strnew(0);
	list->fdr = read(fd, list->mas, 3096);
	list->i = 0;
	t3c(list);
	while (list->mas[list->i])
	{
		lstuse(list);
		list->i++;
	}
}

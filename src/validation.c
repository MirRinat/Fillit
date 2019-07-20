/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:43:34 by bantario          #+#    #+#             */
/*   Updated: 2019/07/04 20:48:42 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		points_and_sq(char *str)
{
	int sq;
	int pt;
	int i;

	sq = 0;
	pt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			sq++;
		if (str[i] == '.')
			pt++;
		i++;
	}
	if (!(sq == 4 && pt == 12))
		return (0);
	return (1);
}

int		carry(char *str)
{
	if ((str[4] != '\n' && str[9] != '\n' && str[14] != '\n' &&
				str[19] != '\n'))
		return (0);
	return (1);
}

int		ft_police(char *str)
{
	int valid;
	int i;

	valid = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if ((i + 1) <= 20 && str[i + 1] == '#')
				valid++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				valid++;
			if ((i + 5) <= 20 && str[i + 5] == '#')
				valid++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				valid++;
		}
		i++;
	}
	return (valid);
}

int		valid(char *str, t_sq *sq)
{
	int valid;

	valid = 0;
	if (!(carry(str)) || !(points_and_sq(str)))
		return (0);
	valid = ft_police(str);
	if (!(valid == 6 || valid == 8))
		return (0);
	if (valid == 8)
		sq->count++;
	return (1);
}

void	errror(void)
{
	ft_putstr("error\n");
	exit(0);
}

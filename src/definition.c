/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:27:57 by bglinda           #+#    #+#             */
/*   Updated: 2019/07/06 18:28:01 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		def_width(char *str)
{
	int min;
	int max;
	int i;
	int width;

	max = 0;
	min = 6;
	width = 0;
	i = 0;
	while (!(str[i] == '\n' && str[i + 1] == '\n'))
	{
		if (str[i] == '#')
		{
			if (i % 5 < min)
				min = i % 5;
			if ((i % 5) > max)
				max = i % 5;
		}
		i++;
	}
	width = max - min + 1;
	return (width);
}

int		def_height(char *str)
{
	int	min;
	int max;
	int i;
	int height;

	max = 0;
	min = 6;
	height = 0;
	i = 0;
	while (!(str[i] == '\n' && str[i + 1] == '\n'))
	{
		if (str[i] == '#')
		{
			if (i / 5 < min)
				min = i / 5;
			if ((i / 5) > max)
				max = i / 5;
		}
		i++;
	}
	height = max - min + 1;
	return (height);
}

int		def_min_x(char *str)
{
	int	min_x;
	int	i;

	min_x = 6;
	i = 0;
	while (!(str[i] == '\n' && str[i + 1] == '\n'))
	{
		if (str[i] == '#')
		{
			if ((i % 5) < min_x)
				min_x = i % 5;
		}
		i++;
	}
	return (min_x);
}

int		def_min_y(char *str)
{
	int	min_y;
	int i;

	min_y = 6;
	i = 0;
	while (!(str[i] == '\n' && str[i + 1] == '\n'))
	{
		if (str[i] == '#')
		{
			if ((i / 5) < min_y)
				min_y = i / 5;
		}
		i++;
	}
	return (min_y);
}

int		ft_sqrt(int num)
{
	int	a;

	a = 2;
	while (a * a < num)
		a++;
	return (a);
}

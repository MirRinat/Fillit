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

int	dots_and_sharps(char *str)
{
	int sharp;
	int dot;
	int i;

	sharp = 0;
	dot = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			sharp++;
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (!(sharp == 4 && dot == 12))
		return (0);
	return (1);
}

int	additional(char *str)
{
	if ((str[4] != '\n' && str[9] != '\n' && str[14] != '\n' &&
				str[19] != '\n'))
		return (0);
	return (1);
}

int	validation(char *str)
{
	int i;
	int valid;

	i = 0;
	valid = 0;
	if (!(additional(str)) || !(dots_and_sharps(str)))
		return (0);
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
	if (!(valid == 6 || valid == 8))
		return (0);
	return (1);
}

void	fault(void)
{
	write(1, "error\n", 6);
	exit(0);
}

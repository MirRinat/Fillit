/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:59:59 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/18 20:59:59 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		r;
	long	nb;

	r = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			r = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str < 48 || *str > 57)
			break ;
		nb = nb * 10 + (*str - '0') * r;
		if (r > 0 && nb < 0)
			return (-1);
		if (r < 0 && nb > 0)
			return (0);
		str++;
	}
	return (nb);
}

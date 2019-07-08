/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:26:20 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/23 20:26:20 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	length(long nb)
{
	size_t		len;

	len = 0;
	if (nb <= 0)
	{
		len++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int			len;
	char		*num;
	long		nb;

	nb = n;
	len = length(nb);
	if (!(num = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	num[len] = '\0';
	if (nb == 0)
		num[0] = '0';
	if (nb < 0)
	{
		num[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		num[--len] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (num);
}

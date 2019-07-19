/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:05:32 by bglinda           #+#    #+#             */
/*   Updated: 2019/06/01 11:05:32 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char const *s1, char const *s2, int nb)
{
	char *result;

	result = ft_strjoin(s1, s2);
	if (result)
	{
		if (nb == 1 || nb == 3)
			free((char *)s1);
		if (nb == 2 || nb == 3)
			free((char *)s2);
	}
	return (result);
}

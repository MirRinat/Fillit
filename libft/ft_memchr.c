/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:24:58 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/18 19:24:58 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *src, int c, size_t n)
{
	const char	*s;
	size_t		i;

	s = (char *)src;
	i = 0;
	while (i < n)
	{
		if (s[i] == (char)c)
			return ((char *)src + i);
		i++;
	}
	return (0);
}

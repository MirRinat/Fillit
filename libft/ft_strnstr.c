/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:48:30 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/17 17:48:30 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s, const char *find, size_t n)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(find);
	if (!*find)
		return ((char *)s);
	while (s[i] != '\0' && i < n)
	{
		j = 0;
		while (find[j] == s[i + j] && i + j < n)
		{
			if (j == len - 1)
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (0);
}

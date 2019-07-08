/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:55:15 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/12 17:55:15 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s, const char *find)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(find);
	if (!*find)
		return ((char *)s);
	while (s[i] != '\0')
	{
		while (find[j] == s[i + j])
		{
			j++;
			if (find[j] == '\0')
				return ((char *)s + i);
		}
		j = 0;
		i++;
	}
	return (0);
}

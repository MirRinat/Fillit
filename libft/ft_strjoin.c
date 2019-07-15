/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:55:05 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/23 13:55:05 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*p;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(p = (char *)malloc(len * sizeof(char) + 1)))
		return (0);
	p = ft_strcpy(p, s1);
	p = ft_strcat(p, s2);
	p[len] = '\0';
	return (p);
}

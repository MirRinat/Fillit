/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:16:59 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/23 13:16:59 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		len_s;
	int		i;

	i = 0;
	if (!s || !f)
		return (0);
	len_s = ft_strlen(s);
	if (!(p = (char *)malloc(len_s * sizeof(char) + 1)) || !s)
		return (0);
	while (s[i] != '\0')
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}

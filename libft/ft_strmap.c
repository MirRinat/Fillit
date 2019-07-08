/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:03:56 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/23 13:03:56 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	size_t	len_s;
	size_t	i;

	i = 0;
	if (s && f)
	{
		len_s = ft_strlen(s);
		if (!(p = (char *)malloc((len_s + 1) * sizeof(char))))
			return (0);
		while (s[i] != '\0')
		{
			p[i] = f(s[i]);
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (0);
}

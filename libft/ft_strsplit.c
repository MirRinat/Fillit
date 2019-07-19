/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:13:13 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/23 16:13:13 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char *s, char c)
{
	size_t		i;
	size_t		w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			w++;
		}
		else
			i++;
	}
	return (w);
}

static char		**ft_split(char **split, char *s, char c, size_t w)
{
	size_t		i;
	size_t		k;
	size_t		start;

	i = 0;
	k = 0;
	start = 0;
	while (s[i] != '\0' && k < w)
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			if (!(split[k] = ft_strsub(s, start, i - start)))
				free(split);
			k++;
		}
		else
			i++;
	}
	split[k] = NULL;
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**split;
	size_t		k;

	split = NULL;
	if (s)
	{
		k = ft_count_words((char *)s, c);
		if (!(split = (char **)malloc((k + 1) * sizeof(char *))))
			return (NULL);
		split = ft_split(split, (char *)s, c, k);
	}
	return (split);
}

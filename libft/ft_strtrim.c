/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:30:30 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/23 14:30:30 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*p;
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	k = len - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k--;
	if (i == len || k == 0)
		return (ft_strnew(0));
	if (!(p = (char *)malloc((k - i + 1) * sizeof(char))))
		return (NULL);
	while (i <= k)
		p[j++] = s[i++];
	p[j] = '\0';
	return (p);
}

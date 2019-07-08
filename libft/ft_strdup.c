/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:19:43 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/24 14:41:26 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		len;
	char	*s;

	len = ft_strlen(src);
	if (!(s = (char*)malloc(len * sizeof(char) + 1)))
		return (NULL);
	ft_strcpy(s, src);
	if (s == NULL)
		return (NULL);
	return (s);
}

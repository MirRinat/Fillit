/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:04:39 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/19 18:04:39 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_strnew(size_t size)
{
	void	*p;

	if ((size + 1) == 0 || !(p = (void *)malloc((size + 1) * sizeof(void))))
		return (NULL);
	p = ft_bzero(p, size + 1);
	return (p);
}

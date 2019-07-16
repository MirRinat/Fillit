/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:05:33 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/26 20:05:33 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlist;
	t_list	*t;
	t_list	*begin;

	if (!lst || !f)
		return (NULL);
	t = f(lst);
	if (!(nlist = ft_lstnew(t->content, t->content_size)))
		return (NULL);
	begin = nlist;
	lst = lst->next;
	while (lst)
	{
		t = f(lst);
		if (!(nlist->next = ft_lstnew(t->content, t->content_size)))
		{
			free(nlist);
			return (NULL);
		}
		nlist = nlist->next;
		lst = lst->next;
	}
	return (begin);
}

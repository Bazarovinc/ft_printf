/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:49:20 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_free(t_list **p, t_list **buf, t_list **l)
{
	if (!(*p = ft_lstnew((*buf)->content, (*buf)->content_size)))
	{
		while (*l)
		{
			*p = (*l)->next;
			free((*l)->content);
			free(l);
			*l = *p;
		}
		return (1);
	}
	return (0);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *buf;
	t_list *list;
	t_list *p;

	if (!lst || !f)
		return (NULL);
	buf = f(lst);
	if (ft_free(&p, &buf, &list) == 1)
		return (NULL);
	lst = lst->next;
	list = p;
	while (lst)
	{
		buf = f(lst);
		if (ft_free(&(p->next), &buf, &list) == 1)
			return (NULL);
		p = p->next;
		lst = lst->next;
	}
	return (list);
}

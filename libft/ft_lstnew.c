/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:52:45 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	*ft_clean(char *s, t_list *l)
{
	free(s);
	free(l);
	return (NULL);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if ((list->content = (char*)malloc(sizeof(char) * content_size)))
		{
			list->content = ft_strncpy(list->content, content,
							content_size);
			list->content_size = content_size;
		}
		else
			ft_clean(list->content, list);
	}
	list->next = NULL;
	return (list);
}

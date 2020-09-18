/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:35:34 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*sr;
	unsigned char	*ds;
	size_t			delta;

	if (dst < src)
	{
		sr = (unsigned char *)src;
		ds = (unsigned char *)dst;
		delta = 1;
	}
	else if (dst > src)
	{
		sr = (unsigned char *)src + len - 1;
		ds = (unsigned char *)dst + len - 1;
		delta = -1;
	}
	else
		return (dst);
	while (len--)
	{
		*ds = *sr;
		ds += delta;
		sr += delta;
	}
	return (dst);
}

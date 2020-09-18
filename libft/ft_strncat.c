/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:57:06 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t size;
	size_t i;

	size = ft_strlen(s1);
	i = 0;
	while (i < n && s2[i])
	{
		s1[size] = s2[i];
		i++;
		size++;
	}
	s1[size] = '\0';
	return (s1);
}

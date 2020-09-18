/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:43:13 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t index_1;
	size_t index_2;

	index_1 = 0;
	if (ft_strlen((char*)needle) == 0 || !needle)
		return ((char*)haystack);
	if (ft_strlen((char*)haystack) == 0 && !haystack &&
			ft_strlen((char*)needle) > len)
		return (NULL);
	while (index_1 < len && haystack[index_1] != '\0')
	{
		index_2 = 0;
		while (haystack[index_1 + index_2] == needle[index_2]
				&& index_2 + index_1 < len)
		{
			if (needle[index_2 + 1] == '\0')
				return ((char *)(haystack + index_1));
			index_2++;
		}
		index_1++;
	}
	return (NULL);
}

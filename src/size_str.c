/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:14:57 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/30 16:27:59 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t	size_str(void)
{
	size_t size;

	if (g_pstr.str == NULL)
	{
		return (0);
	}
	if (g_pstr.str[0] == '\0' && g_pstr.type != 'c')
		return (0);
	else if (g_pstr.str[0] == '\0' && g_pstr.type == 'c')
		return (1);
	else if (g_pstr.str_size != 0)
		return (g_pstr.str_size);
	else
		size = ft_strlen(g_pstr.str);
	return (size);
}

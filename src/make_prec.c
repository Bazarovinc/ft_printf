/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:56:13 by root              #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	make_prec(void)
{
	size_t i;
	size_t size;

	if (g_pstr.str_size < g_pstr.prec && g_pstr.prec != 0)
		if (g_pstr.type == 'd' || g_pstr.type == 'i' || g_pstr.type == 'u' ||
			g_pstr.type == 'x' || g_pstr.type == 'X' || g_pstr.type == 'o' ||
			g_pstr.type == 'b')
		{
			size = g_pstr.prec - g_pstr.str_size;
			i = 0;
			while (i < size)
			{
				write(1, "0", 1);
				i++;
			}
			g_pstr.size += i;
		}
}

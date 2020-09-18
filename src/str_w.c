/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:42:38 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:56:07 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t	str_w(void)
{
	size_t	sy_w;

	sy_w = 0;
	if (g_pstr.prec != 0 && g_pstr.prec <= g_pstr.width &&
		g_pstr.prec > g_pstr.str_size)
		sy_w = g_pstr.width - g_pstr.prec;
	else if (g_pstr.prec >= g_pstr.width)
		sy_w = 0;
	else
		sy_w = g_pstr.width - g_pstr.str_size;
	return (sy_w);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_5_L.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 11:34:18 by ctelma            #+#    #+#             */
/*   Updated: 2020/01/02 17:26:18 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	len_5_l(void)
{
	if (g_pstr.type == 'f' || g_pstr.type == 'F' || g_pstr.type == 'e' ||
		g_pstr.type == 'E' || g_pstr.type == 'a' || g_pstr.type == 'A' ||
		g_pstr.type == 'g' || g_pstr.type == 'G')
		f(va_arg(g_pstr.args, long double));
}

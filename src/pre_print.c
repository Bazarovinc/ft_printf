/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:26:50 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/22 16:37:34 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void		pre_print(void)
{
	if (g_pstr.type == 'c' || g_pstr.type == 's')
		print_cs();
	else if (g_pstr.type == 'i' || g_pstr.type == 'd' || g_pstr.type == 'u' ||
		g_pstr.type == 'f' || g_pstr.type == 'F')
		print_diuf();
	else if (g_pstr.type == 'x' || g_pstr.type == 'X' || g_pstr.type == 'o'
		|| g_pstr.type == 'b')
		print_base();
	else if (g_pstr.type == 'p')
		print_p();
}

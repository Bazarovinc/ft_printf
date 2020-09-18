/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:38:58 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/23 14:47:05 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void		u(unsigned long long num)
{
	if (num == 0 && g_pstr.prec == 0 && g_pstr.prec_flag)
		g_pstr.str = NULL;
	else
		g_pstr.str = ft_itoa_u(num);
	g_pstr.num = 1;
	g_pstr.space = 0;
	g_pstr.hash = 0;
	g_pstr.plus = 0;
}

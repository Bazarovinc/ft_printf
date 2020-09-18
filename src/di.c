/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:24:58 by ctelma            #+#    #+#             */
/*   Updated: 2020/01/02 14:04:15 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static long long	check_num(long long n)
{
	if (n < 0)
	{
		g_pstr.num = -1;
		if (g_pstr.space == 1)
			g_pstr.space = 0;
		if ((g_pstr.zero == 1 && g_pstr.width != 0) || g_pstr.prec != 0)
			n = -n;
		else
			g_pstr.str_minus = 1;
	}
	else
		g_pstr.num = 1;
	return (n);
}

static void			print_sign(char sign)
{
	write(1, &sign, 1);
	g_pstr.size++;
}

void				di(long long num)
{
	num = check_num(num);
	if (num == 0 && g_pstr.prec == 0 && g_pstr.prec_flag)
		g_pstr.str = NULL;
	else
		g_pstr.str = ft_itoa_l(num);
	g_pstr.str_size = size_str();
	if (g_pstr.width <= g_pstr.str_size && g_pstr.plus && g_pstr.num > 0 &&
		g_pstr.prec == 0)
		print_sign('+');
	else if (g_pstr.width <= g_pstr.str_size && g_pstr.num < 0 &&
				g_pstr.prec == 0 && g_pstr.str_minus == 0)
		print_sign('-');
	g_pstr.hash = 0;
}

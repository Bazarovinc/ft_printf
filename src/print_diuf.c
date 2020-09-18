/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:15:31 by ctelma            #+#    #+#             */
/*   Updated: 2020/01/02 16:26:29 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	if_width(void)
{
	if (g_pstr.zero == 0 && g_pstr.plus == 0 && g_pstr.str_minus)
		space_forward(' ', '\0');
	else if (g_pstr.zero == 1 && g_pstr.plus == 0 && g_pstr.num > 0)
		space_forward('0', '\0');
	else if (g_pstr.zero == 0 && g_pstr.plus == 1 && g_pstr.num > 0)
		space_forward(' ', '+');
	else if (g_pstr.zero == 1 && g_pstr.plus == 1 && g_pstr.num > 0)
		space_forward('0', '+');
	else if (g_pstr.zero == 0 && g_pstr.num < 0 && g_pstr.str_minus != 1)
		space_forward(' ', '-');
	else if (g_pstr.zero == 1 && g_pstr.num < 0)
		space_forward('0', '-');
	else if (g_pstr.zero == 0 && g_pstr.plus == 0)
		space_forward(' ', '\0');
}

static void	if_prec(void)
{
	if ((g_pstr.plus && g_pstr.num > 0) || g_pstr.num < 0 ||
			g_pstr.space)
	{
		g_pstr.size++;
		if (g_pstr.plus && g_pstr.num > 0)
			write(1, "+", 1);
		else if (g_pstr.num < 0)
			write(1, "-", 1);
		else if (g_pstr.space)
			write(1, " ", 1);
	}
	make_prec();
	ft_print();
}

static void	if_space(void)
{
	write(1, " ", 1);
	g_pstr.size++;
	ft_print();
}

void		print_diuf(void)
{
	if (g_pstr.width > g_pstr.str_size && g_pstr.minus == 0)
		if_width();
	else if (g_pstr.width > g_pstr.str_size && g_pstr.minus == 1)
		space_back();
	else if (g_pstr.space && g_pstr.prec == 0)
		if_space();
	else if (g_pstr.space && (g_pstr.type == 'f' || g_pstr.type == 'F'))
		if_space();
	else if (g_pstr.prec != 0 && g_pstr.type != 'f' && g_pstr.type != 'F')
		if_prec();
	else
		ft_print();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xXob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:13:40 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	if_prec(void)
{
	if (g_pstr.hash)
	{
		if (g_pstr.type == 'x' || g_pstr.type == 'X' ||
			g_pstr.type == 'b')
		{
			g_pstr.size += 2;
			hash();
		}
		else if (g_pstr.type == 'o')
		{
			g_pstr.size++;
			hash();
		}
	}
	make_prec();
	ft_print();
}

void		print_base(void)
{
	if (g_pstr.width > g_pstr.str_size && g_pstr.minus == 0)
	{
		if (g_pstr.zero == 0)
			space_forward(' ', '\0');
		if (g_pstr.zero)
			space_forward('0', '\0');
	}
	else if (g_pstr.width > g_pstr.str_size && g_pstr.minus == 1)
		space_back();
	else if (g_pstr.space)
	{
		write(1, " ", 1);
		g_pstr.size++;
		ft_print();
	}
	else if (g_pstr.prec != 0)
		if_prec();
	else
		ft_print();
}

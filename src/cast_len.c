/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ophuong <ophuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:57:54 by ophuong           #+#    #+#             */
/*   Updated: 2019/12/29 17:24:58 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	len_1_hh(void)
{
	if (g_pstr.type == 'd' || g_pstr.type == 'i')
		di((int8_t)va_arg(g_pstr.args, int64_t));
	else if (g_pstr.type == 'u')
		u((unsigned char)va_arg(g_pstr.args, int64_t));
	else if (g_pstr.type == 'o' || g_pstr.type == 'x' || g_pstr.type == 'X')
		base((unsigned char)va_arg(g_pstr.args, int64_t));
}

static void	len_2_h(void)
{
	if (g_pstr.type == 'd' || g_pstr.type == 'i')
		di((short)va_arg(g_pstr.args, int64_t));
	else if (g_pstr.type == 'u')
		u((unsigned short)va_arg(g_pstr.args, int64_t));
	else if (g_pstr.type == 'o' || g_pstr.type == 'x' || g_pstr.type == 'X')
		base((unsigned short)va_arg(g_pstr.args, int64_t));
}

static void	len_3_l(void)
{
	if (g_pstr.type == 'd' || g_pstr.type == 'i')
		di(va_arg(g_pstr.args, long));
	else if (g_pstr.type == 'u')
		u(va_arg(g_pstr.args, unsigned long));
	else if (g_pstr.type == 'o' || g_pstr.type == 'x' || g_pstr.type == 'X')
		base(va_arg(g_pstr.args, unsigned long));
	else if (g_pstr.type == 'f' || g_pstr.type == 'F')
		f(va_arg(g_pstr.args, double));
}

static void	len_4_ll(void)
{
	if (g_pstr.type == 'd' || g_pstr.type == 'i')
		di(va_arg(g_pstr.args, long long));
	else if (g_pstr.type == 'u')
		u(va_arg(g_pstr.args, unsigned long long));
	else if (g_pstr.type == 'o' || g_pstr.type == 'x' || g_pstr.type == 'X'
		|| g_pstr.type == 'b')
		base(va_arg(g_pstr.args, unsigned long long));
}

void		cast_len(void)
{
	if (g_pstr.len == 1)
		len_1_hh();
	else if (g_pstr.len == 2)
		len_2_h();
	else if (g_pstr.len == 3)
		len_3_l();
	else if (g_pstr.len == 4)
		len_4_ll();
	else if (g_pstr.len == 5)
		len_5_l();
}

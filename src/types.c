/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:28:52 by ctelma            #+#    #+#             */
/*   Updated: 2020/01/03 20:22:13 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	dioux(void)
{
	if (g_pstr.type == 'd' || g_pstr.type == 'i')
		di(va_arg(g_pstr.args, int));
	else if (g_pstr.type == 'u')
		u(va_arg(g_pstr.args, unsigned int));
	else if (g_pstr.type == 'o' || g_pstr.type == 'x' || g_pstr.type == 'X'
		|| g_pstr.type == 'b')
		base(va_arg(g_pstr.args, unsigned int));
	else if (g_pstr.type == 'f' || g_pstr.type == 'F')
		f(va_arg(g_pstr.args, double));
}

static void	check_len(void)
{
	if (g_pstr.len == 5 && (g_pstr.type == 'd' || g_pstr.type == 'i' ||
		g_pstr.type == 'u' || g_pstr.type == 'o' || g_pstr.type == 'x' ||
		g_pstr.type == 'X' || g_pstr.type == 'b'))
		g_pstr.len = g_pstr.len2;
}

static void	prec_zero(void)
{
	if (g_pstr.prec_flag)
	{
		if (g_pstr.type != 'f' && g_pstr.type != 'F')
			g_pstr.zero = 0;
	}
}

static int	check_type(void)
{
	if (g_pstr.type == 'd' || g_pstr.type == 'i' || g_pstr.type == 'u'
		|| g_pstr.type == 'o' || g_pstr.type == 'x' || g_pstr.type == 'X'
		|| g_pstr.type == 'f' || g_pstr.type == 'F' || g_pstr.type == 'b'
		|| g_pstr.type == 's' || g_pstr.type == 'c' || g_pstr.type == 'p'
		|| g_pstr.type == '%')
		return (1);
	return (0);
}

void		types(const char *format)
{
	g_pstr.type = format[g_pstr.i];
	if (check_type())
	{
		prec_zero();
		check_len();
		if (g_pstr.len != 0)
			cast_len();
		else if (g_pstr.type == 'd' || g_pstr.type == 'i' || g_pstr.type == 'u'
			|| g_pstr.type == 'o' || g_pstr.type == 'x' || g_pstr.type == 'X'
			|| g_pstr.type == 'f' || g_pstr.type == 'F' || g_pstr.type == 'b')
			dioux();
		else if (g_pstr.type == 's')
			s(va_arg(g_pstr.args, char *));
		else if (g_pstr.type == 'c')
			c(va_arg(g_pstr.args, int));
		else if (g_pstr.type == 'p')
			p(va_arg(g_pstr.args, void*));
		else if (g_pstr.type == '%')
		{
			c(g_pstr.type);
			g_pstr.type = 'c';
		}
		g_pstr.non_print++;
	}
}

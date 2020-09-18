/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:56:11 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/30 15:29:31 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	flag(char c)
{
	if (c == '-' || c == '+' || c == '0' || c == '#' || c == ' ')
		return (1);
	return (0);
}

void		check_flags(const char *s)
{
	while (flag(s[g_pstr.i]))
	{
		if (s[g_pstr.i] == '-')
			g_pstr.minus = 1;
		else if (s[g_pstr.i] == '+')
			g_pstr.plus = 1;
		else if (s[g_pstr.i] == '0')
			g_pstr.zero = 1;
		else if (s[g_pstr.i] == '#')
			g_pstr.hash = 1;
		else if (s[g_pstr.i] == ' ')
			g_pstr.space = 1;
		g_pstr.i++;
		g_pstr.non_print++;
	}
	if (g_pstr.plus && g_pstr.space)
		g_pstr.space = 0;
	if (g_pstr.zero && g_pstr.minus)
		g_pstr.zero = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ophuong <ophuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:59:25 by ophuong           #+#    #+#             */
/*   Updated: 2020/01/02 17:40:56 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	check_len(char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	return (0);
}

static void	double_m(const char *s)
{
	if (s[g_pstr.i] == 'h' && s[g_pstr.i + 1] == 'h' &&
		(g_pstr.len <= 1 || g_pstr.len == 5))
	{
		if (g_pstr.len == 5)
			g_pstr.len2 = 1;
		else
			g_pstr.len = 1;
		g_pstr.len = 1;
	}
	else if (s[g_pstr.i] == 'l' && s[g_pstr.i + 1] == 'l' &&
		(g_pstr.len <= 4 || g_pstr.len == 5))
	{
		if (g_pstr.len == 5)
			g_pstr.len2 = 4;
		else
			g_pstr.len = 4;
	}
	g_pstr.i += 2;
	g_pstr.non_print += 2;
}

static void	one_m(const char *s)
{
	if (s[g_pstr.i] == 'h' && s[g_pstr.i + 1] != 'h' && (g_pstr.len <= 2 ||
		g_pstr.len == 5))
	{
		if (g_pstr.len == 5)
			g_pstr.len2 = 2;
		else
			g_pstr.len = 2;
	}
	else if (s[g_pstr.i] == 'l' && s[g_pstr.i + 1] != 'l' &&
		(g_pstr.len <= 3 || g_pstr.len == 5))
	{
		if (g_pstr.len == 5)
			g_pstr.len2 = 3;
		else
			g_pstr.len = 3;
	}
	g_pstr.i++;
	g_pstr.non_print++;
}

static void	l(const char *s)
{
	if (s[g_pstr.i] == 'L' && g_pstr.len <= 5)
	{
		g_pstr.len = 5;
		g_pstr.len2 = 5;
		g_pstr.i++;
		g_pstr.non_print++;
	}
}

void		length(const char *s)
{
	size_t i;

	i = g_pstr.i;
	while (check_len(s[g_pstr.i]))
	{
		if ((s[g_pstr.i] == 'l' || s[g_pstr.i] == 'h')
			&& s[g_pstr.i] != s[g_pstr.i + 1])
			one_m(s);
		if ((s[g_pstr.i] == 'l' || s[g_pstr.i] == 'h')
			&& s[g_pstr.i] == s[g_pstr.i + 1])
			double_m(s);
		if (s[g_pstr.i] == 'L')
			l(s);
		if (i == g_pstr.i)
		{
			g_pstr.i++;
			g_pstr.non_print++;
		}
		i = g_pstr.i;
	}
}

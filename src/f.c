/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:20:20 by ctelma            #+#    #+#             */
/*   Updated: 2020/01/03 17:08:14 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "../header/ft_printf.h"

static long double	check_num(long double n)
{
	t_float_union n1;

	n1.pf_union = n;
	if (n1.float_parts.sign == 1)
	{
		g_pstr.num = -1;
		if (g_pstr.space == 1)
			g_pstr.space = 0;
		n = -n;
	}
	else
		g_pstr.num = 1;
	return (n);
}

static void			make_str(char *s1, char *s2, long double n)
{
	g_pstr.str = rounding(ft_strjoin(s1, s2), n);
	free(s1);
	free(s2);
}

static void			make_f(long double n, int t, int i)
{
	unsigned long long int	n1;
	unsigned long long int	n3;
	char					*s1;
	char					*s2;
	long double				n2;

	n1 = (unsigned long long int)n;
	s1 = ft_itoa_u(n1);
	s2 = check_mem(t + 2);
	n2 = n - n1;
	check_point_f(s2, i, t);
	i++;
	while (t)
	{
		n2 *= 10;
		n3 = (unsigned long long int)n2;
		s2[i] = (char)(n3 + '0');
		n2 = n2 - n3;
		t--;
		i++;
	}
	s2[i] = '\0';
	make_str(s1, s2, n2);
}

static void			print_sign(char sign)
{
	write(1, &sign, 1);
	g_pstr.size++;
}

void				f(long double n)
{
	if (check_inf(n))
		;
	else
	{
		n = check_num(n);
		if (g_pstr.prec == 0 && g_pstr.prec_flag == 0)
			make_f(n, 6, 0);
		else
			make_f(n, g_pstr.prec, 0);
	}
	g_pstr.str_size = size_str();
	if (g_pstr.width <= g_pstr.str_size && g_pstr.plus && g_pstr.num > 0)
		print_sign('+');
	if (g_pstr.width <= g_pstr.str_size && g_pstr.num < 0)
		print_sign('-');
}

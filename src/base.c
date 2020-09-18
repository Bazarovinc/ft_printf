/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:20:05 by ctelma            #+#    #+#             */
/*   Updated: 2020/01/02 14:55:50 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		hash_nonzero(void)
{
	if (g_pstr.type != 'b')
	{
		write(1, "0", 1);
		g_pstr.size++;
	}
	else if (g_pstr.type == 'b')
	{
		write(1, "2", 1);
		write(1, "x", 1);
		g_pstr.size += 2;
	}
	if (g_pstr.type == 'x' || g_pstr.type == 'X')
	{
		write(1, &g_pstr.type, 1);
		g_pstr.size++;
	}
}

static void		zero_num(void)
{
	if (g_pstr.type == 'o' && g_pstr.hash)
	{
		g_pstr.str = (char*)malloc(sizeof(char) * 2);
		g_pstr.str[0] = '0';
		g_pstr.str[1] = '\0';
	}
	else
		g_pstr.str = NULL;
	g_pstr.hash = 0;
}

static void		del_hash(void)
{
	if (g_pstr.width > g_pstr.str_size && g_pstr.zero)
		g_pstr.hash = 0;
	else if (g_pstr.prec > g_pstr.str_size)
		g_pstr.hash = 0;
}

void			base(unsigned long long num)
{
	if (g_pstr.prec == 0 && g_pstr.prec_flag == 1 && num == 0)
		zero_num();
	else
	{
		if (g_pstr.type == 'o')
			g_pstr.str = ft_itoa_base(num, 8, 0);
		else if (g_pstr.type == 'x')
			g_pstr.str = ft_itoa_base(num, 16, 0);
		else if (g_pstr.type == 'X')
			g_pstr.str = ft_itoa_base(num, 16, 1);
		else if (g_pstr.type == 'b')
			g_pstr.str = ft_itoa_base(num, 2, 0);
	}
	g_pstr.str_size = size_str();
	if (g_pstr.hash && num == 0)
		g_pstr.hash = 0;
	if (g_pstr.type == 'o')
		del_hash();
	g_pstr.plus = 0;
	g_pstr.space = 0;
	if (g_pstr.hash == 1 && g_pstr.width <= g_pstr.str_size && g_pstr.prec == 0)
		hash_nonzero();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:28:52 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static size_t	print_plus(size_t i)
{
	if (g_pstr.type == 'd' || g_pstr.type == 'i' || g_pstr.type == 'f' ||
		g_pstr.type == 'F')
	{
		if (g_pstr.plus == 1 && g_pstr.num > 0)
		{
			write(1, "+", 1);
			i++;
		}
		else if (g_pstr.num < 0 && g_pstr.str_minus == 0)
		{
			write(1, "-", 1);
			i++;
		}
	}
	return (i);
}

static size_t	hash_before(size_t i)
{
	if (g_pstr.hash)
	{
		if (g_pstr.type == 'x' || g_pstr.type == 'X')
		{
			hash();
			i += 2;
		}
		else if (g_pstr.type == 'o')
		{
			hash();
			i++;
		}
	}
	return (i);
}

void			space_back(void)
{
	size_t	i;
	size_t	sy_w;

	sy_w = str_w();
	i = 0;
	i = one_space_forward(i);
	i = print_plus(i);
	i = hash_before(i);
	make_prec();
	ft_print();
	while (i < sy_w)
	{
		write(1, " ", 1);
		i++;
	}
	g_pstr.size += i;
}

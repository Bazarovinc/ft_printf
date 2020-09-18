/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:28:52 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:52:51 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static size_t	ft_sign(size_t i, char sign, char c)
{
	if ((g_pstr.type == 'i' || g_pstr.type == 'd' || g_pstr.type == 'u' ||
		g_pstr.type == 'f' || g_pstr.type == 'F') && sign != '\0')
	{
		if (c == ' ')
			i++;
		else if (c == '0')
		{
			write(1, &sign, 1);
			i++;
		}
	}
	return (i);
}

static void		sign_after(char sign, char c)
{
	if ((g_pstr.type == 'i' || g_pstr.type == 'd' || g_pstr.type == 'u' ||
		g_pstr.type == 'f' || g_pstr.type == 'F') && sign != '\0')
	{
		if (c == ' ')
		{
			write(1, &sign, 1);
		}
	}
}

static size_t	hash_before(size_t i, char c)
{
	if (g_pstr.hash)
	{
		if (g_pstr.type == 'x' || g_pstr.type == 'X' || g_pstr.type == 'b')
		{
			if (c == '0')
				hash();
			i += 2;
		}
		else if (g_pstr.type == 'o')
		{
			if (c == '0')
				hash();
			i++;
		}
	}
	return (i);
}

static void		hash_after(char c)
{
	if (g_pstr.hash)
	{
		if (g_pstr.type == 'x' || g_pstr.type == 'X' || g_pstr.type == 'o'
			|| g_pstr.type == 'b')
			if (c == ' ')
				hash();
	}
}

void			space_forward(char c, char sign)
{
	size_t	i;
	size_t	sy_w;

	i = 0;
	sy_w = str_w();
	i = one_space_forward(i);
	i = ft_sign(i, sign, c);
	i = hash_before(i, c);
	while (i < sy_w)
	{
		write(1, &c, 1);
		i++;
	}
	hash_after(c);
	sign_after(sign, c);
	make_prec();
	g_pstr.size += i;
	ft_print();
}

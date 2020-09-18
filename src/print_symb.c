/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:48:35 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/20 16:21:57 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	print_symb(const char *s)
{
	int symb;

	g_pstr.i++;
	g_pstr.non_print++;
	if (s[g_pstr.i] >= '0' && s[g_pstr.i] <= '9')
	{
		symb = ft_atoi(s + g_pstr.i);
		while (s[g_pstr.i] >= '0' && s[g_pstr.i] <= '9')
		{
			g_pstr.i++;
			g_pstr.non_print++;
		}
		ft_putchar(symb);
	}
}

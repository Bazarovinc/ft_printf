/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:29:32 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/30 19:19:15 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	p(void *ptr)
{
	char *s;

	s = ft_itoa_base((unsigned long)ptr, 16, 0);
	if (ptr == 0 && g_pstr.prec == 0 && g_pstr.prec_flag)
	{
		g_pstr.str = ft_strdup("0x");
		g_pstr.type = 'x';
		g_pstr.hash = 0;
	}
	else if ((g_pstr.zero == 0 && (g_pstr.width != 0 || g_pstr.width == 0))
		&& g_pstr.prec == 0)
	{
		g_pstr.str = ft_strjoin("0x", s);
		g_pstr.hash = 0;
		free(s);
	}
	else
	{
		g_pstr.type = 'x';
		g_pstr.hash = 1;
		g_pstr.str = s;
	}
}

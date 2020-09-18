/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:32:15 by root              #+#    #+#             */
/*   Updated: 2019/12/30 15:32:47 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	precision(const char *s)
{
	while (s[g_pstr.i] == '.')
	{
		g_pstr.prec_flag = 1;
		g_pstr.i++;
		g_pstr.non_print++;
		if (s[g_pstr.i] >= '0' && s[g_pstr.i] <= '9')
		{
			g_pstr.prec = ft_atoi(s + g_pstr.i);
			while (s[g_pstr.i] >= '0' && s[g_pstr.i] <= '9')
			{
				g_pstr.i++;
				g_pstr.non_print++;
			}
		}
	}
}

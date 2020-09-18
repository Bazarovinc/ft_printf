/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:51:21 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	width(const char *s)
{
	if (s[g_pstr.i] >= '0' && s[g_pstr.i] <= '9')
	{
		g_pstr.width = ft_atoi(s + g_pstr.i);
		while (s[g_pstr.i] >= '0' && s[g_pstr.i] <= '9')
		{
			g_pstr.i++;
			g_pstr.non_print++;
		}
	}
}

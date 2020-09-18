/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:15:43 by ctelma            #+#    #+#             */
/*   Updated: 2020/01/03 16:33:41 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		check_inf(long double n)
{
	if (1.0 / 0.0 == n)
	{
		g_pstr.str = ft_strdup("inf");
		g_pstr.num = 1;
	}
	else if (-1.0 / 0.0 == n)
	{
		g_pstr.str = ft_strdup("inf");
		g_pstr.space = 0;
		g_pstr.num = -1;
	}
	else if (n != n)
	{
		g_pstr.str = ft_strdup("nan");
		g_pstr.type = 's';
	}
	if (g_pstr.str != NULL)
	{
		g_pstr.zero = 0;
		g_pstr.prec = 0;
		g_pstr.prec_flag = 0;
		return (1);
	}
	return (0);
}

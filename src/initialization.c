/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:07:44 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	first_time(void)
{
	g_pstr.i = 0;
	g_pstr.size = 0;
	g_pstr.non_print = 0;
	g_pstr.str = NULL;
	g_pstr.plus = 0;
	g_pstr.minus = 0;
	g_pstr.width = 0;
	g_pstr.zero = 0;
	g_pstr.type = '\0';
	g_pstr.str_size = 0;
	g_pstr.hash = 0;
	g_pstr.prec = 0;
	g_pstr.space = 0;
	g_pstr.num = 0;
	g_pstr.len = 0;
	g_pstr.len2 = 0;
	g_pstr.prec_flag = 0;
	g_pstr.str_minus = 0;
}

static void	reinitialization(void)
{
	free(g_pstr.str);
	g_pstr.str = NULL;
	g_pstr.plus = 0;
	g_pstr.minus = 0;
	g_pstr.width = 0;
	g_pstr.prec = 0;
	g_pstr.zero = 0;
	g_pstr.type = '\0';
	g_pstr.str_size = 0;
	g_pstr.hash = 0;
	g_pstr.space = 0;
	g_pstr.num = 0;
	g_pstr.len = 0;
	g_pstr.len2 = 0;
	g_pstr.prec_flag = 0;
	g_pstr.str_minus = 0;
}

void		initialization(int check)
{
	if (check == 0)
		first_time();
	else if (check == 1)
		reinitialization();
}

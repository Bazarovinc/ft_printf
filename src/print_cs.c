/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:29:19 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/20 16:21:57 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	print_cs(void)
{
	if (g_pstr.width > g_pstr.str_size && g_pstr.minus == 0)
	{
		if (g_pstr.zero == 0)
			space_forward(' ', '\0');
		else if (g_pstr.zero == 1)
			space_forward('0', '\0');
	}
	else if (g_pstr.width > g_pstr.str_size && g_pstr.minus == 1)
		space_back();
	else
		ft_print();
}

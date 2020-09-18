/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:34:49 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/20 16:39:07 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	print_p(void)
{
	if (g_pstr.width > g_pstr.str_size && g_pstr.zero == 0 && g_pstr.minus == 0)
	{
		space_forward(' ', '\0');
	}
	else if (g_pstr.width > g_pstr.str_size && g_pstr.minus)
		space_back();
	else
		ft_print();
}

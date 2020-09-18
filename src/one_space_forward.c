/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_space_forward.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:44:44 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/20 16:21:57 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t	one_space_forward(size_t i)
{
	if (g_pstr.space == 1 && (g_pstr.type == 'd'
		|| g_pstr.type == 'i' || g_pstr.type == 'f'))
	{
		write(1, " ", 1);
		i = 1;
	}
	else
		i = 0;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:42:58 by root              #+#    #+#             */
/*   Updated: 2019/12/29 17:21:48 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	hash(void)
{
	if (g_pstr.type == 'x' || g_pstr.type == 'X')
	{
		write(1, "0", 1);
		write(1, &g_pstr.type, 1);
	}
	else if (g_pstr.type == 'b')
	{
		write(1, "2", 1);
		write(1, "x", 1);
	}
	else if (g_pstr.type == 'o')
		write(1, "0", 1);
}

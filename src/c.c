/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:09:58 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/30 16:28:40 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	c(int c)
{
	if (c == 0)
	{
		g_pstr.str = (char*)malloc(sizeof(char) * 1);
		g_pstr.str[0] = '\0';
	}
	else
	{
		g_pstr.str = (char*)malloc(sizeof(char) * 2);
		g_pstr.str[0] = c;
		g_pstr.str[1] = '\0';
	}
}

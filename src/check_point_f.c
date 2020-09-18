/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_point_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:34:49 by ctelma            #+#    #+#             */
/*   Updated: 2020/01/02 15:45:20 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	check_point_f(char *s, int i, int t)
{
	if (g_pstr.hash && t == 0)
		s[i] = '.';
	else if (t != 0)
		s[i] = '.';
}
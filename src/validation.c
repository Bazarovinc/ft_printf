/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:28:52 by ctelma            #+#    #+#             */
/*   Updated: 2020/01/03 19:49:53 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	validation(const char *format)
{
	g_pstr.i++;
	g_pstr.non_print++;
	if (format[g_pstr.i] == '%')
		ft_putchar('%');
	else if (format[g_pstr.i] == '\0')
		;
	else
	{
		check_flags(format);
		width(format);
		precision(format);
		length(format);
		types(format);
		g_pstr.str_size = size_str();
		pre_print();
		initialization(1);
	}
}

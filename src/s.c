/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:28:52 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/30 20:36:45 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		null_str(void)
{
	if (g_pstr.prec <= 6 && g_pstr.prec != 0)
	{
		g_pstr.str = (char*)malloc(sizeof(char) * (g_pstr.prec + 1));
		g_pstr.str = ft_strncpy(g_pstr.str, "(null)", g_pstr.prec);
		g_pstr.str[g_pstr.prec] = '\0';
	}
	else if ((g_pstr.prec == 0 && g_pstr.prec_flag == 0) || (g_pstr.prec != 0
	&& g_pstr.prec_flag && g_pstr.prec > 6))
		g_pstr.str = ft_strdup("(null)");
	g_pstr.prec = 0;
}

void			s(char *s)
{
	size_t size;

	if (s != NULL)
		size = ft_strlen(s);
	else
		size = 0;
	if (s == NULL)
		null_str();
	else if (g_pstr.prec == 0 && g_pstr.prec_flag == 0)
		g_pstr.str = ft_strdup(s);
	else if (g_pstr.prec != 0 && g_pstr.prec_flag &&
				g_pstr.prec <= size)
	{
		g_pstr.str = (char*)malloc(sizeof(char) * (g_pstr.prec + 1));
		g_pstr.str = ft_strncpy(g_pstr.str, s, g_pstr.prec);
		g_pstr.str[g_pstr.prec] = '\0';
		g_pstr.prec = 0;
	}
	else if (g_pstr.prec != 0 && g_pstr.prec_flag &&
				g_pstr.prec > size)
	{
		g_pstr.str = ft_strdup(s);
		g_pstr.prec = 0;
	}
}

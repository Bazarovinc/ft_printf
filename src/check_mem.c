/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 13:36:05 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/23 13:39:08 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*check_mem(size_t size)
{
	char *s;

	if (!(s = (char*)malloc(sizeof(char) * size)))
	{
		write(1, "Memmory error!\n", 15);
		exit(0);
	}
	return (s);
}

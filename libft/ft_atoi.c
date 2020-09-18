/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:45:37 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

static int	ft_skip(const char *s, int *sign)
{
	size_t i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13) || s[i] == 48)
		i++;
	if (s[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int			res;
	int			sign;
	size_t		i;
	long long	fl;

	sign = 1;
	i = 0;
	res = 0;
	fl = 0;
	i = ft_skip(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((fl > ((fl * 10) + str[i] - '0')) && sign == 1)
			return (-1);
		if ((fl > ((fl * 10) + str[i] - '0')) && sign == -1)
			return (0);
		res = (res * 10) + str[i] - '0';
		fl = (fl * 10) + str[i] - '0';
		i++;
	}
	return (res * sign);
}

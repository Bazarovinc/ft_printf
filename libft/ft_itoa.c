/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:57:59 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

static size_t	ft_size(int nb)
{
	size_t size;

	size = 0;
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static char		*ft_conv(int n, char *s, size_t i, int sign)
{
	size_t	j;
	char	c;

	while (n > 0)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	j = 0;
	if (sign == -1)
	{
		s[i] = '-';
		i++;
	}
	i--;
	while (i > j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i--;
		j++;
	}
	return (s);
}

static	char	*ft_min_int(int n)
{
	char *s;

	s = ft_strnew(0);
	s = "\0";
	if (n == 0)
	{
		s = ft_strdup("0\0");
	}
	if (n == -2147483648)
	{
		s = ft_strdup("-2147483648\0");
	}
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		flag;
	size_t	i;

	flag = 1;
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		flag = -1;
	}
	if (n == 0 || n == -2147483648)
		return (ft_min_int(n));
	i = 0;
	if (flag == -1)
	{
		s = ft_strnew(ft_size(n) + 1);
	}
	else
		s = ft_strnew(ft_size(n));
	if (!s)
		return (NULL);
	s = ft_conv(n, s, i, flag);
	return (s);
}

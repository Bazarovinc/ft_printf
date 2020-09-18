/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:00:06 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 17:22:39 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static char	*zero_str(char *s)
{
	s = (char*)malloc(sizeof(char) * 2);
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

static int	size_of_num(unsigned long long n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void	ft_strrev(char *s, int size)
{
	int		i;
	char	c;

	i = 0;
	size--;
	while (i < size)
	{
		c = s[i];
		s[i] = s[size];
		s[size] = c;
		i++;
		size--;
	}
}

char		*ft_itoa_u(unsigned long long num)
{
	int		size;
	int		i;
	char	*str;

	str = NULL;
	if (num == 0)
		return (zero_str(str));
	size = size_of_num(num);
	str = (char*)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (num != 0)
	{
		str[i] = (char)((num % 10) + '0');
		num /= 10;
		i++;
	}
	ft_strrev(str, size);
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:02:30 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static size_t	ft_nbrlen(unsigned long long nbr, int base)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base;
		len += 1;
	}
	return (len);
}

static char		*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	buff;

	i = 0;
	length = ft_strlen(str);
	while (length - 1 > i)
	{
		buff = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buff;
		length--;
		i++;
	}
	return (str);
}

char			*ft_itoa_base(unsigned long long n, int base, int uppercase)
{
	char	*str;
	int		i;
	int		length;

	if (base < 2 || base > 16)
		return (NULL);
	length = ft_nbrlen(n, base);
	str = (char*)malloc(sizeof(*str) * (length + 1));
	i = 0;
	while (i < length)
	{
		if (base > 10 && (n % base >= 10) && uppercase)
			str[i++] = (char)((n % base) - 10 + 'A');
		else if (base > 10 && (n % base >= 10))
			str[i++] = (char)((n % base) - 10 + 'a');
		else
			str[i++] = (char)((n % base) + '0');
		n /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

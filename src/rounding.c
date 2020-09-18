/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:25:59 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:59:51 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static char	*change_size(char *s, int size)
{
	int		i;
	int		j;
	char	*s1;

	s1 = (char*)malloc(sizeof(char) * (size + 1));
	s1[0] = '1';
	i = 0;
	j = 1;
	while (s[i] != '\0')
	{
		s1[j] = s[i];
		i++;
		j++;
	}
	s1[j] = '\0';
	free(s);
	return (s1);
}

static char	*cycle(unsigned long long int n1, int size, int size1, char *s)
{
	if (n1 >= 5)
	{
		while (size >= 0)
		{
			if (s[size] != '9' && n1 >= 5 && s[size] != '.')
			{
				s[size] = s[size] + 1;
				return (s);
			}
			else if (s[size] == '9' && n1 >= 5 && size != 0)
			{
				n1 = (unsigned long long int)(s[size] - '0');
				s[size] = '0';
				size--;
			}
			else if (s[size] == '9' && n1 >= 5 && size == 0)
			{
				s[size] = '0';
				return (change_size(s, size1));
			}
			else if (s[size] == '.')
				size--;
		}
	}
	return (s);
}

char		*rounding(char *s, long double n)
{
	int						size;
	int						size1;
	unsigned long long int	n1;

	size = (int)(ft_strlen(s) - 1);
	size1 = size + 1;
	n *= 10;
	n1 = (int)n;
	return (cycle(n1, size, size1, s));
}

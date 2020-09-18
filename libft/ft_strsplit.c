/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:34:35 by ctelma            #+#    #+#             */
/*   Updated: 2019/12/29 16:23:36 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	count_words(const char *str, char c)
{
	size_t words;
	size_t i;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_issymb(str[i + 1], c) == 1 && ft_issymb(str[i], c) == 0)
			words++;
		i++;
	}
	return (words);
}

static void	ft_write_word(char *word, const char *str, char c)
{
	size_t i;

	i = 0;
	while (ft_issymb(str[i], c) == 0)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
}

static int	ft_clear(char *s, char **matrix)
{
	size_t i;

	i = 0;
	if (!s)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		return (1);
	}
	return (0);
}

static int	ft_write_matrix(char **matrix, const char *str, char c)
{
	size_t i;
	size_t j;
	size_t word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (ft_issymb(str[i], c) == 0)
		{
			j = 0;
			while (ft_issymb(str[i + j], c) == 0)
				j++;
			matrix[word] = (char*)malloc(sizeof(char) * (j + 1));
			if (ft_clear(matrix[word], matrix) == 1)
				return (1);
			ft_write_word((matrix[word]), (str + i), c);
			word++;
			i += j;
		}
		else
			i++;
	}
	matrix[word] = 0;
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**matrix;
	size_t	count;

	if (!s || !c)
		return (NULL);
	count = count_words(s, c);
	matrix = (char**)malloc(sizeof(char*) * (count + 1));
	if (!matrix)
		return (NULL);
	if (ft_write_matrix(matrix, s, c) == 1)
		return (NULL);
	return (matrix);
}

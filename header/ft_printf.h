/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:42:43 by ctelma            #+#    #+#             */
/*   Updated: 2020/01/03 20:16:59 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef	union
{
	float				pf_union;
	struct
	{
		unsigned int	mantisa : 23;
		unsigned int	exponent : 8;
		unsigned int	sign : 1;
	}					float_parts;
}						t_float_union;

typedef struct s_structure	t_structure;

struct					s_structure
{
	va_list	args;
	size_t	i;
	size_t	size;
	size_t	str_size;
	size_t	width;
	size_t	prec;
	int		str_minus;
	int		prec_flag;
	int		num;
	char	type;
	char	*str;
	int		non_print;
	int		plus;
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		len;
	int		len2;
};

t_structure	g_pstr;

int						ft_printf(const char *format, ...);
void					initialization(int check);
void					validation(const char *format);
void					check_flags(const char *s);
void					width(const char *s);
void					precision(const char *s);
void					length(const char *s);
void					types(const char *format);
void					cast_len(void);
void					len_5_l(void);
void					di(long long num);
void					u(unsigned long long num);
void					base(unsigned long long num);
void					c(int c);
void					s(char *s);
void					p(void *ptr);
void					f(long double n);
char					*ft_itoa_base(unsigned long long n,
								int base, int uppercase);
char					*ft_itoa_l(long long nbr);
char					*ft_itoa_u(unsigned long long num);
int						check_inf(long double n);
char					*rounding(char *s, long double n);
void					check_point_f(char *s, int i, int t);
size_t					size_str(void);
void					pre_print(void);
void					print_cs(void);
void					print_diuf(void);
void					print_base(void);
void					print_p(void);
void					space_forward(char c, char sign);
void					space_back(void);
size_t					one_space_forward(size_t i);
size_t					str_w(void);
void					print_symb(const char *s);
void					hash(void);
void					make_prec(void);
void					ft_print();
char					*check_mem(size_t size);

#endif

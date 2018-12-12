/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:37:10 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/12 15:08:13 by lmariott         ###   ########.fr       */
/*   Updated: 2018/12/11 19:59:28 by lmariott         ###   ########.fr       */
/*   Updated: 2018/12/11 15:38:26 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

# define ABS(Value) ((Value) < 0) ? (-Value) : (Value)

int								ft_char(va_list *ap, char *tab);
int								ft_int(va_list *ap, char *tab);
int								ft_char_star(va_list *ap, char *tab);
int								ft_unsigned_int_o(va_list *ap, char *tab);
int								ft_unsigned_int_u(va_list *ap, char *tab);
int								ft_unsigned_int_x_maj(va_list *ap, char *tab);
int								ft_unsigned_int_x_min(va_list *ap, char *tab);
int								ft_p_address(va_list *ap, char *tab);
int								ft_any(char c, char *tab);
int								ft_double_f(va_list *ap, char *tab);


void							ft_flag_convert(va_list *ap, char **tab, unsigned long long *x);
void							ft_fill_precision(char **tab, int len,
		unsigned long long x);
int								ft_ret(char **tab, int len);
void							ft_fill_size_min(char **tab, int len);
int								ft_cas_0(char *tab, unsigned long long x);

int								ft_strcmp_modif(const char *s1, const char *s2);
int								ft_capture_the_flag(char **tab,
		const char *format, int i);
void							ft_putull_base(unsigned long long nb,
		unsigned long long base);
void							ft_putll_base(long long nb, long long base);
void							ft_putull_base_min(unsigned long long nb, unsigned long long base);
struct							s_list_f
{
	char				*s;
	int		 (*f)(va_list *ap, char *tab);
	struct s_list_f		*next;
};

typedef		struct s_list_f		t_list_f;

t_list_f						*ft_make_maillon(char *s, t_list_f *list);
t_list_f						*ft_make_list_f(void);
int								ft_nbrlen_base(long long nb, long long base);
int								ft_unbrlen_base(unsigned long long nb, unsigned long long base);
int								ft_double_len_left(long double x);
void							ft_flag_convert_int(va_list *ap, char **tab, long long *x);
int								ft_return_int(char *tab, int len, int count);

#endif

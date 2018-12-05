/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:37:10 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/05 13:28:27 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int								ft_char(va_list *ap);
int								ft_int(va_list *ap);
int								ft_char_star(va_list *ap);

int								ft_strcmp_modif(const char *s1, const char *s2);

struct							s_list_f
{
	char				*s;
	int		 (*f)(va_list *ap);
	struct s_list_f		*next;
};

typedef		struct s_list_f		t_list_f;

t_list_f						*ft_make_maillon(char *s, t_list_f *list);
t_list_f						*ft_make_list_f(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:57:28 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/05 10:46:39 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_int(va_list *ap)
{
	int x;

	x = va_arg(*ap, int);
	ft_putnbr(x);
	return (0);
}

int			ft_char_star(va_list *ap)
{
	char *s;

	s = va_arg(*ap, char *);
	ft_putstr(s);
	return (0);
}

int			ft_unsigned_int_o(va_list *ap)
{
	unsigned int x;

	x = va_arg(*ap, unsigned int);
	ft_putull_base(x , 2)
}

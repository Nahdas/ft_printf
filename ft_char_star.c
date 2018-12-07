/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:40:14 by alac              #+#    #+#             */
/*   Updated: 2018/12/07 14:12:49 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_star(va_list *ap, char *tab)
{
	char *s;
	int ret;

	s = va_arg(*ap, char *);
	if ((size_t)tab[5] > ft_strlen(s))
		ret = (int)tab[5];
	else
		ret = (int)ft_strlen(s);
	while ((size_t)tab[5] > ft_strlen(s))
	{
		write(1, " ", 1);
		tab[5]--;
	}
	ft_putstr(s);
	return (ret);
}

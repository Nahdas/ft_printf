/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:16:22 by alac              #+#    #+#             */
/*   Updated: 2018/12/06 16:39:52 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(va_list *ap, char *tab)
{
	char c;

	c = (char)va_arg(*ap, int);
	while (tab[5] > 1)
	{
		ft_putchar(' ');
		tab[5]--;
	}
	ft_putchar(c);
	return (1);
}
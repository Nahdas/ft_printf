/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:16:22 by alac              #+#    #+#             */
/*   Updated: 2018/12/11 13:32:06 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(va_list *ap, char *tab)
{
	char	c;
	int		ret;

	ret = 1;
	if(tab[5] != 0)
		ret = tab[5];
	c = (char)va_arg(*ap, int);
	if (tab[0] == 1)
		ft_putchar(c);
	while (tab[5] > 1)
	{
		ft_putchar(' ');
		tab[5]--;
	}
	if (tab[0] != 1)
		ft_putchar(c);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:42:19 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/06 15:35:09 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unsigned_int_o(va_list *ap, char *tab)
{
	unsigned int	x;
	int				len;

	x = va_arg(*ap, unsigned int);
	len = ft_nbrlen_base(x, 8);
	if (tab[6] == -1)
		tab[6] = 1;
	if (tab[1] == 1)
	{
		write(1, "error.", 6);
		return (0);
	}
	while (tab[5] > tab[6] && tab[5] > len)
	{
		tab[5]--;
		write(1, " ", 1);
	}
	while ((tab[6] > len) || tab[2] == 1)
	{
		tab[2] = 0;
		tab[6]--;
		write(1, "0", 1);
	}
	ft_putull_base(x , 8);
	return (0);
}

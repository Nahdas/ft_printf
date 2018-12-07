/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:31:36 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/07 11:33:06 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unsigned_int_x_maj(va_list *ap, char *tab)
{
	unsigned int	x;
	int				len;

	x = va_arg(*ap, unsigned int);
	len = ft_nbrlen_base(x, 16);
	if (tab[6] == -1)
		tab[6] = 1;
	while (tab[5] > tab[6] && tab[5] > len && tab[0] != 1)
	{
		tab[5]--;
		write(1, " ", 1);
	}
	while ((tab[6] > len))
	{
		tab[2] = 0;
		tab[6]--;
		write(1, "0", 1);
	}
	ft_putull_base(x , 16);
	if (tab[0] == 1)
	{
		while (tab[5] > tab[6] && tab[5] > len)
		{
			tab[5]--;
			write(1, " ", 1);
		}
	}
	return (0);
}

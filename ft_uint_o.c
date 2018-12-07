/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:42:19 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/07 16:37:44 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unsigned_int_o(va_list *ap, char *tab)
{
	unsigned int	x;
	int				len;
	int				ret;

	x = va_arg(*ap, unsigned int);
	len = ft_nbrlen_base(x, 8);
	len += (int)tab[2];
	if (x == 0 && tab[6] == 0)
		len = 0;
	if (tab[6] == -1)
		tab[6] = 1;
	if (len > tab[5] && len > tab[6])
		ret = len;
	if (tab[5] > len && tab[5] > tab[6])
		ret = (int)tab[5];
	if (tab[6] > len && tab[6] > tab[5])
		ret = (int)tab[6];
	tab[1] = tab[5];
	while (tab[5] > tab[6] && tab[5] > len && tab[0] != 1)
	{
		tab[5]--;
		if (tab[3] == 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
	}
	tab[7] = tab[6];
	while ((tab[6] > len) || tab[2] == 1)
	{
		tab[2] = 0;
		if (tab[6] != 0)
			tab[6]--;
		else
			tab[1]++;
		write(1, "0", 1);
	}
	if (tab[6] == 0 && x == 0)
		return (tab[1] > 0 ? tab[1] : 0);
	ft_putull_base(x , 8);
	if (tab[0] == 1)
	{
		while (tab[5] > tab[7] && tab[5] > len)
		{
			tab[5]--;
			write(1, " ", 1);
		}
	}
	return (ret);
}

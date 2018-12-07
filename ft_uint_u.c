/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:04:02 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/07 13:51:56 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unsigned_int_u(va_list *ap, char *tab)
{
	unsigned int	x;
	int				len;
	int				ret;

	x = va_arg(*ap, unsigned int);
	len = ft_nbrlen_base(x, 10);
	if (tab[6] == -1)
		tab[6] = 1;
	if (len > tab[5] && len > tab[6])
		ret = len;
	if (tab[5] > len && tab[5] > tab[6])
		ret = tab[5];
	if (tab[6] > len && tab[6] > tab[5])
		ret = tab[6];
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
	ft_putull_base(x , 10);
	if (tab[0] == 1)
	{
		while (tab[5] > tab[6] && tab[5] > len)
		{
			tab[5]--;
			write(1, " ", 1);
		}
	}
	return (ret);
}

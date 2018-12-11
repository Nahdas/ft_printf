/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:17:48 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/11 15:57:06 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_percent(va_list *ap, char *tab)
{
	int			len;

	len = 1;
	if (!ap)
		return (0);
	if (tab[6] == -1)
		tab[6] = 1;
	if (tab[5] == 0)
		tab[5] = 1;
	tab[7] = tab[5];
	tab[5]--;
	if (tab[0] != 1)
	{
		while (tab[5]--)
			write(1, " ", 1);
	}
	write(1, "%", 1);
	if (tab[0] == 1)
	{
		while (tab[5]--)
			write(1, " ", 1);
	}
	return (len > tab[7] ? len : tab[7]);
}

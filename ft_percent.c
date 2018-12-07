/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:17:48 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/07 20:32:48 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_percent(va_list *ap, char *tab)
{
	int			len;

	len = 1;
	if (!ap)
		return (0);
	if (tab[5] == -1)
		tab[5] = 1;
	if (tab[0] != 1)
	{
		while (tab[5]--)
			write(1, " ", 1);
	}
	if (tab[6] > 0)
		write(1, "%", 1);
	if (tab[0] == 1)
	{
		while (tab[5]--)
			write(1, " ", 1);
	}
	return (tab[5]);
}

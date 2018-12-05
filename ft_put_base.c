/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:51:46 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/05 10:58:05 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char			*ft_create_base(int base)
{
	char *bazz;
	int i;

	i = 0;
	if(!(bazz = (char *)malloc(sizeof(char) * base + 1)))
		return (NULL);
	while (i < base)
	{
		if (i < 10)
			bazz[i] = '0' + i;
		else
			bazz[i] = 'A' + i - 10;
		i++;
	}
	bazz[i] = '\0';
	return (bazz);
}


void			ft_putull_base(unsigned long long nb, unsigned long long base)
{
	char *bazz;

	bazz = ft_create_base(base);
	if (nb < base)
		write(1 , &(bazz[nb]), 1);
	if (nb >= base)
	{
		ft_putull_base(nb / base, base);
		write(1 , &(bazz[nb % base]), 1);
	}
	free(bazz);
}

void			ft_putll_base(long long nb, long long base)
{
	char *bazz;

	bazz = ft_create_base(base);
	if (nb < base && nb >= 0)
		write (1, &bazz[nb], 1);
	if (nb < 0)
	{
		write (1, "-", 1);
		ft_putll_base(-nb, base);
	}
	if (nb >= base)
	{
		ft_putll_base(nb / base, base);
		write(1, &bazz[nb % base], 1);
	}
	free(bazz);
}

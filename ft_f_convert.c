/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:57:28 by lmariott          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/12/05 14:51:55 by lmariott         ###   ########.fr       */
=======
/*   Updated: 2018/12/05 16:29:00 by alac             ###   ########.fr       */
>>>>>>> c4a55039b69742fc50c9e16e93cfcf6f7e6a2817
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_int(va_list *ap, char *tab)
{
	char	*str;
	int 	i;
	int 	minus;

<<<<<<< HEAD
	if (!tab)
		return (0);
	x = va_arg(*ap, int);
	ft_putnbr(x);
=======
	str = va_arg(*ap, char *);
	i = 0;
	minus = 0;
	if (tab[0] == 1)
	{
		minus++;
		ft_putchar('-');
	}
	if (tab[1] == 1)
		ft_putchar('+');
	if (tab[0] == 1)
		ft_putchar('-');
	if (tab[4] == 1)
		ft_putchar(' ');
	if (tab[5] >= 1 && tab[6] == 0)
	{
		if (!(str = (char*)malloc(sizeof(str) * (tab[5] + 1))))
			return (0);
		while (i < (int)(tab[5]) - 1)
		{
			if (tab[3] == 1)
				ft_putchar('0');
			ft_putchar(' ');
			i++;
		}
	}
	if (tab[5] >= 1 && tab[6] >= 1)
	{
		while (tab[5] - tab[6] > 0)
		{
			ft_putchar(' ');
			tab[5] = tab[5] - 1;
		}
		while (tab[6] > 0)
		{
			ft_putchar('0');
			tab[6] = tab[6] - 1;
		}
	}
	ft_putstr(&str[minus]);
>>>>>>> c4a55039b69742fc50c9e16e93cfcf6f7e6a2817
	return (0);
}

int			ft_char_star(va_list *ap, char *tab)
{
	char *s;

	if (!tab)
		return (0);
	s = va_arg(*ap, char *);
	ft_putstr(s);
	return (0);
}

int			ft_unsigned_int_o(va_list *ap, char *tab)
{
	unsigned int x;

	if (!tab)
		return (0);
	x = va_arg(*ap, unsigned int);
	ft_putull_base(x , 2);
	return (0);
}

int		ft_char(va_list *ap, char *tab)
{
	char	c;
	char	*str;
	int i;

	i = 0;
	c = (char)va_arg(*ap, int);
	if (tab[5] >= 1)
	{
		if (!(str = (char*)malloc(sizeof(str) * (tab[5] + 1))))
			return (0);
		while (i < (int)(tab[5]) - 1)
		{
			str[i] = ' ';
			i++;
		}
		str[i] = c;
		str[i + 1] = '\0';
	}
	ft_putstr(str);
	return (1);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:40:14 by alac              #+#    #+#             */
/*   Updated: 2018/12/07 19:16:57 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_precision(char *s, char *tab)
{
	int i;

	i = 0;
	while ((int)tab[6] > i && s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	if ((int)tab[6] == 0)
		ft_putstr(s);
	return (0);
}

static int		ft_size(char *s, char *tab)
{
	int i;

	i = 0;

	if (s[0] != '\0')
	{
		while ((int)tab[5] > i + (int)ft_strlen(s) - (int)tab[6])
		{
			write(1, " ", 1);
			i++;
		}
		return (0);
	}
	while ((int)tab[5] > i + (int)ft_strlen(s))
	{
		write(1, " ", 1);
		i++;
	}
	return (0);

}

static int 		ft_pre_char(char *s, char *tab)
{
	int i;

	i = 0;
	if (tab[0] == 1)
	{
		ft_precision(s, tab);
		return(-1);
	}
	return (0);
}

int		ft_char_star(va_list *ap, char *tab)
{
	char	*s;
	int		i;


	i = 0;
	if (tab[6] == -1)
		tab[6] = 0;
	s = va_arg(*ap, char *);
	if (!s)
	{
		write(1, "\0", 1);
		return (0);
	}
	i = ft_pre_char(s, tab);
	ft_size(s, tab);
	if (i != -1)
		ft_precision(s, tab);
	else
		i = 0;
	if ((size_t)tab[5] >= ft_strlen(s))
		return ((int)tab[5] + i);
	if (tab[6] > 0)
		return ((int)ft_strlen(s) - ((int)ft_strlen(s) - (int)tab[6]) + i);
	if ((size_t)tab[5] < ft_strlen(s) && tab[6] == 0)
		return ((int)ft_strlen(s));
	return ((int)ft_strlen(s) + i);
}

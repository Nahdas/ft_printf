/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capture_the_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:29:20 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/05 14:02:27 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_first_flag(char **tab, char *format, int i)
{
	while (format[i] &&
			(format[i] == '#' ||
			 format[i] == ' ' ||
			 format[i] == '0' ||
			 format[i] == '-' ||
			 format[i] == '+'))
	{
		if (format[i] == '-')
			*tab[0] = 1;
		if (format[i] == '+')
			*tab[1] = 1;
		if (format[i] == '#')
			*tab[2] = 1;
		if (format[i] == '0')
			*tab[3] = 1;
		if (format[i] == ' ')
			*tab[4] = 1;
		i++;
	}
	return (i);
}

static int			ft_second_flag(char **tab, char *format, int i)
{
	int j;

	j = 0;
	while(format[i] == '.' ||
			(format[i] >= '0' && format[i] >= '9'))
	{
		if (format[i] == '.')
		{
			nb = ft_strdup(s);
			*tab[5] = ft_atoi(nb);
			j = 0;
			i++;
		}
		format[i] = s[j];
		i++;
		j++;
	}
	nb = ft_strdup(s);
	if (*tab[5] != 0)
		*tab[6] = ft_atoi(nb);
	else
		*tab[5] = ft_atoi(nb);
	return (i);
}

static int			ft_third_flag(char **tab, char *format, int i)
{
	if (format[i] == 'h')
	{
		tab[7]++;
		if (format[++i] == 'h')
		{
			tab[7]++;
			i++;
		}
	}
	if (format[i] == 'l' && tab[7] == 0)
	{
		tab[7] += 2;
		if (format[++i] == 'l')
		{
			tab[7] += 2;
			i++;
		}
	}
	if (format[i] == 'L' && tab[7] == 0)
	{
		tab[7]++;
		i++;
	}
	return (i)
}

int					ft_capture_the_flag(char **tab, char *format, int i)
{
	i = ft_first_flag(tab, format, i);
	i = ft_second_flag(tab, format, i);
	i = ft_third_flag(tab, format, i);
	return (i);
}

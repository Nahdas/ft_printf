/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:52:17 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/05 09:17:55 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_list_f	*list;
	t_list_f	*head;
	int			i;

	i = 0;
	list = NULL;
	head = NULL;
	va_start(ap, format);
	list = ft_make_list_f();
	if (!(head = (t_list_f*)malloc(sizeof(t_list_f))))
		return (0);
	while(format[i])
	{
		head = list;
		if (format[i] == '%')
		{
			i++;
			while (head && !ft_strcmp_modif(&format[i], head->s))
				head = head->next;
			(head->f)(&ap);
			i++;
		}
		write(1, &format[i++], 1);
	}
	va_end(ap);
	return (0);
}

int		main()
{
	ft_printf("int = %d\nstring = %s\n", 42, "BONJOUR");
	return (0);
}

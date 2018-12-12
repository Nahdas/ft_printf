/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:53:24 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/12 15:07:43 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list_f	*ft_make_maillon(char *s, t_list_f *list)
{
	t_list_f	*head;

	head = NULL;
	if (!(head = (t_list_f*)malloc(sizeof(t_list_f))))
		return (NULL);
	head->next = list;
	head->s = s;
	return (head);
}

t_list_f	*ft_make_list_f(void)
{
	t_list_f *list;
	t_list_f *head;

	list = NULL;
	head = NULL;
	head = ft_make_maillon("d", list);
	head->f = &ft_int;
	list = head;
	head = ft_make_maillon("s", list);
	head->f = &ft_char_star;
	list = head;
	head = ft_make_maillon("i", list);
	head->f = &ft_int;
	list = head;
	head = ft_make_maillon("c", list);
	head->f = &ft_char;
	list = head;
	head = ft_make_maillon("p", list);
	head->f = &ft_p_address;
	list = head;
	head = ft_make_maillon("o", list);
	head->f = &ft_unsigned_int_o;
	list = head;
	head = ft_make_maillon("u", list);
	head->f = &ft_unsigned_int_u;
	list = head;
	head = ft_make_maillon("x", list);
	head->f = &ft_unsigned_int_x_min;
	list = head;
	head = ft_make_maillon("X", list);
	head->f = &ft_unsigned_int_x_maj;
	list = head;
	head = ft_make_maillon("f", list);
	head->f = &ft_double_f;
	list = head;

	return (list);
}

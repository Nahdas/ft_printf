/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:53:24 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/07 11:15:21 by alac             ###   ########.fr       */
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
	return (list);
}

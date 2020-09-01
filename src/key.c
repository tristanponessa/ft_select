/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 08:55:14 by trponess          #+#    #+#             */
/*   Updated: 2019/09/16 10:45:47 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

long	key_value(void)
{
	char buffer[6];

	ft_bzero(&buffer, 4);
	read(0, buffer, 4);
	return (buffer[0] + buffer[1] + buffer[2] + buffer[3]);
}

int		press_key(t_string *list)
{
	long key;

	tputs(tgetstr("cl", NULL), 1, ft_tputchar);
	if (size_list(list) == 0)
		return (1);
	display(list);
	key = key_value();
	if (key == RIGHT)
		move(&list, 1);
	if (key == LEFT)
		move(&list, -1);
	if (key == UP)
		move(&list, -(get_term_size('w') / (get_gap(list) + 1)));
	if (key == DOWN)
		move(&list, get_term_size('w') / (get_gap(list) + 1));
	if (key == SPACE)
		select_elem(&list);
	if (key == ENTER)
		return (2);
	if (key == DELETE || key == RETURN)
		delete_elem(&list);
	if (key == ESC)
		return (1);
	list_obj(list);
	return (0);
}

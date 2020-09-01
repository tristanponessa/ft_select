/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 08:55:04 by trponess          #+#    #+#             */
/*   Updated: 2019/09/16 10:23:27 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		out_borders(int y, int x)
{
	if (y >= get_term_size('h') || x >= get_term_size('w'))
	{
		tputs(tgetstr("cl", NULL), 1, ft_tputchar);
		ft_putstr_fd(0, "too small");
		return (1);
	}
	return (0);
}

int		outofrange(t_string *list, int on, int len)
{
	int i;
	int adv;
	int dir;

	i = on;
	adv = 0;
	dir = 1;
	if (len < 0)
	{
		len *= -1;
		dir = -1;
	}
	while (i > -1 && list[i].visible != -1)
	{
		i += dir;
		if (list[i].visible == 1)
			adv++;
		if (adv == len)
			return (0);
	}
	if (list[i].visible == -1 || i == -1)
		return (1);
	return (-1);
}

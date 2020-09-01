/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 08:54:18 by trponess          #+#    #+#             */
/*   Updated: 2019/09/16 10:23:57 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_tputchar(int c)
{
	write(0, &c, 1);
	return (0);
}

static void		activate_effects(t_string list)
{
	if (list.selected == 1)
		ft_putstr_fd(0, KINVV);
	if (list.on == 1)
		ft_putstr_fd(0, KUNDL);
}

static void		adv_vars(int *y, int *x, int *c)
{
	*y += 1;
	*c = 0;
	*x = 0;
}

static void		init_vars(int *y, int *x, int *i, int *c)
{
	*y = 0;
	*x = 0;
	*i = 0;
	*c = 0;
}

void			display(t_string *list)
{
	int y;
	int x;
	int i;
	int c;

	init_vars(&y, &x, &i, &c);
	while (list[i].visible != -1)
	{
		if (list[i].visible == 1)
		{
			if (out_borders(y, x))
				return ;
			tputs(tgoto(tgetstr("cm", NULL), x, y), 1, ft_tputchar);
			activate_effects(list[i]);
			ft_putstr_fd(0, list[i].name);
			++c;
			x += (get_gap(list) + 1);
			if (c == get_term_size('w') / (get_gap(list) + 1))
				adv_vars(&y, &x, &c);
			ft_putstr_fd(0, KNRM);
		}
		++i;
	}
}

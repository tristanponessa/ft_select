/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 08:54:34 by trponess          #+#    #+#             */
/*   Updated: 2019/09/16 15:09:27 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	goto_next(t_string **list, int len, int dir, int i)
{
	int c;

	c = 0;
	while (1)
	{
		(*list)[i].on = 0;
		if ((*list)[i].visible == 1)
		{
			if (c == len)
			{
				(*list)[i].on = 1;
				break ;
			}
			++c;
		}
		i += dir;
	}
}

int		move(t_string **list, int len)
{
	int i;
	int dir;

	i = 0;
	dir = 1;
	while ((*list)[i].visible != -1 && (*list)[i].on == 0)
		++i;
	if (outofrange(*list, i, len) == 1 || outofrange(*list, i, len) == -1)
		return (1);
	if (len < 0)
	{
		len *= -1;
		dir = -1;
	}
	goto_next(list, len, dir, i);
	return (0);
}

void	select_elem(t_string **list)
{
	int i;

	i = 0;
	while ((*list)[i].visible != -1 && (*list)[i].on == 0)
		++i;
	if ((*list)[i].selected == 1)
		(*list)[i].selected = 0;
	else
	{
		(*list)[i].on = 0;
		(*list)[i].selected = 1;
		++i;
		while ((*list)[i].visible != -1)
		{
			if ((*list)[i].visible == 1)
			{
				(*list)[i].on = 1;
				break ;
			}
			++i;
		}
		if ((*list)[i].visible == -1)
			(*list)[0].on = 1;
	}
}

void	delete_elem(t_string **list)
{
	int i;

	i = 0;
	while ((*list)[i].visible != -1 && (*list)[i].on == 0)
		++i;
	(*list)[i].visible = 0;
	(*list)[i].on = 0;
	while ((*list)[i].visible != -1)
	{
		if ((*list)[i].visible == 1)
		{
			(*list)[i].on = 1;
			break ;
		}
		++i;
	}
	if ((*list)[i].visible == -1)
		(*list)[0].on = 1;
}

void	print_selected(t_string *l)
{
	int			i;
	int			j;
	t_string	s[SIZE];

	i = 0;
	j = 0;
	while (l[i].visible != -1)
	{
		if (l[i].visible == 1 && l[i].selected == 1)
			s[j++] = l[i];
		++i;
	}
	s[j].visible = -1;
	i = 0;
	while (i < SIZE && s[i].visible != -1)
	{
		if (s[i].visible == 1)
		{
			if (i - 1 > -1)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(1, s[i].name);
		}
		++i;
	}
}

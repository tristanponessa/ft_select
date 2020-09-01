/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 08:53:36 by trponess          #+#    #+#             */
/*   Updated: 2019/09/21 16:08:06 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			size_list(t_string *l)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (l[i].visible != -1)
	{
		if (l[i].visible == 1)
			++c;
		++i;
	}
	return (c);
}

t_string	*create_list(int ac, char **arg)
{
	int			i;
	t_string	*list;

	list = (t_string*)malloc(sizeof(t_string) * SIZE);
	if (!list)
		return (NULL);
	i = 0;
	while (i < SIZE - 1)
	{
		ft_memset(list[i].name, 300, '\0');
		list[i].visible = -1;
		++i;
	}
	i = 1;
	while (i < ac)
	{
		ft_strcpy(list[i - 1].name, arg[i]);
		list[i - 1].selected = 0;
		list[i - 1].visible = 1;
		++i;
	}
	return (list);
}

int			get_gap(t_string *l)
{
	int big_gap;
	int i;

	big_gap = 0;
	i = 0;
	while (l[i].visible != -1)
	{
		if (ft_strlen(l[i].name) > big_gap)
			big_gap = ft_strlen(l[i].name);
		++i;
	}
	return (big_gap);
}

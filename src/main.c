/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 08:56:08 by trponess          #+#    #+#             */
/*   Updated: 2019/09/16 15:35:51 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_string			*list_obj(t_string *list)
{
	static t_string *l;

	if (list != NULL)
		l = list;
	return (l);
}

static int			valid_name(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isprint(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int			check_args(int ac, char **av)
{
	int i;

	i = 1;
	if (ac <= 1 || ac > SIZE - 1)
	{
		ft_putstr_fd(0, "nb args problem\n");
		return (1);
	}
	while (i < ac)
	{
		if (!valid_name(av[i]) || ft_strlen(av[i]) > 200)
		{
			ft_putstr_fd(0, "one arg has wrong name\n");
			return (1);
		}
		++i;
	}
	return (0);
}

int					main(int argc, char **argv)
{
	t_string	*list;
	int			r;

	if (check_args(argc, argv) == 1)
		return (0);
	list = create_list(argc, argv);
	if (!list)
		ft_exit("t_string malloc failed\n");
	list_obj(list);
	list[0].on = 1;
	setup_term(1);
	while (1)
	{
		r = press_key(list);
		if (r == 1 || r == 2)
			break ;
	}
	setup_term(0);
	if (r == 2)
		print_selected(list);
	free(list);
	return (0);
}

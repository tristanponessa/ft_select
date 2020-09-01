/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 08:53:11 by trponess          #+#    #+#             */
/*   Updated: 2019/09/16 10:27:11 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	signal_handler(int sign)
{
	if (sign >= 1 && sign <= 15)
	{
		setup_term(0);
		ft_putstr_fd(0, "SIGDEAD signal : exiting project \
		, restoring terminal\n");
		exit(EXIT_FAILURE);
	}
	else if (sign == SIGWINCH)
	{
		ft_putstr_fd(0, "SIGWINCH\n");
		ft_putstr_fd(0, tgetstr("cl", NULL));
		display(list_obj(NULL));
	}
	else if (sign == SIGTSTP)
	{
		setup_term(0);
		signal(SIGTSTP, SIG_DFL);
		ioctl(2, TIOCSTI, "\x1A");
		ft_putstr_fd(0, "signal CTRLZ : pausing program\n");
	}
	else if (sign == SIGCONT)
	{
		setup_term(1);
		display(list_obj(NULL));
	}
}

void	init_signal(void)
{
	int i;

	i = 1;
	while (i != 31)
		signal(i++, &signal_handler);
}

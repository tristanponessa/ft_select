/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 08:52:06 by trponess          #+#    #+#             */
/*   Updated: 2019/09/16 10:46:47 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_exit(char *msg)
{
	ft_putstr_fd(2, msg);
	exit(EXIT_FAILURE);
}

void	init_powers(struct termios *term, struct termios *init_term)
{
	*init_term = *term;
	(*term).c_cc[VMIN] = 1;
	(*term).c_cc[VTIME] = 0;
	(*term).c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(0, TCSANOW, term) == -1)
		ft_exit("failed to set attr\n");
	tputs(tgetstr("vi", NULL), 1, ft_tputchar);
	tputs(tgetstr("ti", NULL), 1, ft_tputchar);
	init_signal();
}

void	del_powers(struct termios *init_term)
{
	tputs(tgetstr("ve", NULL), 1, ft_tputchar);
	tputs(tgetstr("te", NULL), 1, ft_tputchar);
	if (tcsetattr(0, TCSANOW, init_term) == -1)
		ft_exit("failed to reset term\n");
}

void	setup_term(int option)
{
	static struct termios init_term;
	static struct termios term;

	if (option == 1)
	{
		if (!isatty(0))
			ft_exit("not a terminal process\n");
		if (getenv("TERM") == NULL)
			ft_exit("terminal not set in env\n");
		if (tcgetattr(0, &term) == -1)
			ft_exit("failed to retreive attr\n");
		if (tgetent(NULL, getenv("TERM")) < 1)
			ft_exit("failed to get term entry\n");
		if (!tgetstr("cm", NULL) || !tgetstr("cl", NULL) || \
			!tgetstr("ve", NULL) \
		|| !tgetstr("te", NULL) || !tgetstr("vi", NULL) || !tgetstr("ti", NULL))
			ft_exit("Terminal lacks some capacities. Use another.");
		init_powers(&term, &init_term);
	}
	else
		del_powers(&init_term);
}

int		get_term_size(char w_h)
{
	struct winsize w;

	if (ioctl(0, TIOCGWINSZ, &w) != 0)
	{
		ft_putstr_fd(0, "ioctl problem");
		return (-1);
	}
	if (w_h == 'w')
		return (w.ws_col);
	else
		return (w.ws_row);
}

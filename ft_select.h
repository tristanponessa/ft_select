/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:54 by trponess          #+#    #+#             */
/*   Updated: 2019/09/15 02:37:50 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/includes/libft.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <termcap.h>
# include <signal.h>
# define UP (27 + 91 + 65)
# define DOWN (27 + 91 + 66)
# define RIGHT (27 + 91 + 67)
# define LEFT (27 + 91 + 68)
# define SPACE 32
# define TAB 9
# define RETURN 127
# define DELETE 4
# define S 115
# define ESC 27
# define ENTER 10
# define SIZE 2000

typedef	struct	s_string
{
	char	name[300];
	int		selected;
	int		visible;
	int		on;

}				t_string;

int				out_borders(int y, int x);
int				outofrange(t_string *list, int on, int len);
int				ft_tputchar(int c);
void			display(t_string *list);
long			key_value();
int				press_key(t_string *list);
void			goto_next(t_string **list, int len, int dir, int i);
int				move(t_string **list, int len);
void			select_elem(t_string **list);
void			delete_elem(t_string **list);
void			print_selected(t_string *l);
int				size_list(t_string *l);
t_string		*create_list(int ac, char **arg);
int				get_gap(t_string *l);
t_string		*list_obj(t_string *list);
void			signal_handler(int sign);
void			init_signal();
void			ft_exit(char *msg);
void			init_powers(struct termios *term, struct termios *init_term);
void			del_powers(struct termios *init_term);
void			setup_term(int option);
int				get_term_size(char w_h);

#endif

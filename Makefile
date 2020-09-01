# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trponess <trponess@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/30 11:59:50 by trponess          #+#    #+#              #
#    Updated: 2019/09/21 16:05:16 by trponess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_select
SRC = src/main.c \
		src/display.c \
		src/key.c \
		src/list.c \
		src/list2.c \
		src/terminal.c \
		src/signal.c \
		src/check_limit.c

OBJ =  $(subst src/, objects/, $(SRC:.c=.o))
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
HEADER_FLAGS = -I .
CC = clang
HEADER = ft_select.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)  
	$(CC) $(CFLAGS) $(OBJ) $(HEADER_FLAGS) $(LIBFT) -o $(NAME) -l termcap

objects/%.o: src/%.c $(HEADER)
	mkdir -p objects/
	$(CC) $(CFLAGS) $(HEADER_FLAGS) -c $< -o $@

$(LIBFT): FORCE
	$(MAKE) -C libft/

FORCE : 

clean:
	$(RM) -rf objects/ && \
	$(MAKE) -C libft/ clean

fclean: clean
	$(RM) $(NAME) && \
	$(MAKE) -C libft fclean && \
	$(RM) -r $(NAME).dSYM

re: fclean all

.PHONY: all clean fclean re FORCE
.SILENT:
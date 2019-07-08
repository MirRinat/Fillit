# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bglinda <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 16:23:03 by bglinda           #+#    #+#              #
#    Updated: 2019/07/05 16:23:31 by bglinda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c definition.c create.c

HEADERS = libft/libft.a

OBJECTS = *.o

all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) $(HEADERS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
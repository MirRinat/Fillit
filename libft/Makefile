# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bglinda <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 16:24:42 by bglinda           #+#    #+#              #
#    Updated: 2019/04/12 16:40:01 by bglinda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_*.c

HEADERS = libft.h

OBJECTS = ft_*.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -I $(HEADERS) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

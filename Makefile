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

LNAM = libft.a

LIBF = ./libft

INCL = ./includes/fillit.h

SRCS = ./src

CCFL = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIBF) re
	@$(CCFL) -L $(LIBF) -lft $(SRCS)/*.c -I $(LIBF)  -o $(NAME)

clean:
	@make -C $(LIBF) clean

fclean: clean
	@make -C $(LIBF) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
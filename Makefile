# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramoukha <ramoukha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 12:17:42 by ramoukha          #+#    #+#              #
#    Updated: 2020/01/01 17:05:56 by ramoukha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP = gcc -Werror -Wextra -Wall 
SRC = srcs/main.c srcs/tools.c srcs/store.c
OB =  main.o tools.o store.o
NAME = fdf  

all : $(NAME)

$(NAME):
	make -C libft/
	$(COMP) -c $(SRC) -I /usr/local/include
	$(COMP) -g -o $(NAME) $(OB)  libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework appKit

clean:
	make -C libft/ clean
	rm -f $(OB)
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all 

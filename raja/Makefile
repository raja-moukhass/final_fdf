# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramoukha <ramoukha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 12:17:42 by ramoukha          #+#    #+#              #
#    Updated: 2020/02/25 15:13:03 by ramoukha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP = gcc -Werror -Wextra -Wall
SRC = srcs/main.c srcs/tools.c srcs/store.c srcs/bresenham.c srcs/mlx.c
OB =  main.o tools.o store.o bresenham.o mlx.o
INC = includes/fdf.h
OB = $(SRC:.c=.o)
NAME = fdf

all : $(NAME)

$(NAME): $(OB)
	make -C libft/
	#$(COMP) -c $(SRC)
	$(COMP) -g -o $(NAME) $(OB) libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework appKit 
	@printf "\033[00;32m"
	@printf "BINARY CREATED\n"
	@printf "\033[00;0m"

%.o : %.c $(INC)
	$(COMP) -c -o $@ $< -I includes/fdf.h
clean:
	make -C libft/ clean
	rm -f $(OB)
	@printf "\033[00;32m"
	@printf "OBJECTS REMOVED\n"
	@printf "\033[00;0m"

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
	@printf "\033[00;32m"
	@printf "BINARY REMOVED\n"
	@printf "\033[00;0m"


re: fclean all

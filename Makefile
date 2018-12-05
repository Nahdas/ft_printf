# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmariott <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 11:49:47 by lmariott          #+#    #+#              #
#    Updated: 2018/12/05 11:10:06 by alac             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libft/
SRC = ft_read.c\
	  test_input.c\
  	  main.c\
	  ft_put_tetri.c\
	  map_generator.c\
	  ft_split_nn.c\
	  ft_letters.c\
	  ft_backtracking.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : lib $(OBJ)
	$(CC) $(OBJ) -o $(NAME) ./libft/libft.a

lib :
	make -C ./libft

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

clean :
	make clean -C ./libft
	rm -f $(OBJ)

re : fclean all

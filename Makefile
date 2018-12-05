# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmariott <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 11:49:47 by lmariott          #+#    #+#              #
#    Updated: 2018/12/05 14:14:58 by lmariott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libft/
SRC = ft_printf.c\
	  ft_list.c\
  	  ft_capture_the_flag.c\
	  ft_f_convert.c\
	  ft_put_base.c\
	  ft_strcmp_modif.c

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

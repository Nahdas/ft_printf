# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmariott <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 11:49:47 by lmariott          #+#    #+#              #
#    Updated: 2018/12/11 17:26:01 by lmariott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libft/
SRC = ft_printf.c\
	  ft_list.c\
  	  ft_capture_the_flag.c\
	  ft_put_base.c\
	  ft_strcmp_modif.c\
	  ft_uint_x_min.c\
	  ft_uint_x_maj.c\
	  ft_uint_u.c\
	  ft_uint_o.c\
	  ft_p_address.c\
	  ft_int.c\
	  ft_char.c\
	  ft_char_star.c\
	  ft_nbrlen_base.c\
	  ft_help.c\
	  ft_percent.c\
	  ft_double_f.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : lib $(OBJ)
	ar rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)

lib :
	make -C ./libft

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

clean :
	make clean -C ./libft
	rm -f $(OBJ)

re : fclean all

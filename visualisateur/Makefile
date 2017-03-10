# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/04 10:13:27 by lcharvol          #+#    #+#              #
#    Updated: 2017/02/04 10:13:29 by lcharvol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualisateur

SRCS =	srcs/aff.c \
		srcs/parcing.c \
		srcs/main.c \
		srcs/other.c \
		srcs/other2.c \
	   

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L../includes/mlx/ -lmlx -framework OpenGL -framework AppKit ../libft/libft.a
	echo "visualisateur done"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

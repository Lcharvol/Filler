# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 03:23:24 by lcharvol          #+#    #+#              #
#    Updated: 2017/01/30 03:23:25 by lcharvol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = resources/players/lcharvol.filler

SRCS := srcs/main.c 
SRCS +=	srcs/tools.c 
SRCS +=	srcs/tools2.c 
SRCS +=	srcs/ft_parcing.c 
SRCS +=	srcs/play.c 
SRCS +=	srcs/play2.c 

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C visualisateur
	gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
	echo "Filler done"

clean:
	make clean -C libft
	make clean -C visualisateur
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C visualisateur
	rm -f $(NAME)

re: fclean all

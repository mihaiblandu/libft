# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mihai.blandu <mihai.blandu@ctif.gov.md>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 14:54:00 by tbenoist          #+#    #+#              #
#    Updated: 2024/02/27 21:29:19 by mihai.bland      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(SRC) 
	@gcc -Wall -Wextra -Werror -c  -Ofast $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all


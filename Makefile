# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 14:54:00 by tbenoist          #+#    #+#              #
#    Updated: 2026/01/25 23:53:58 by mihaiblandu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(shell find src -name "*.c")

OBJ = $(notdir $(SRC:.c=.o))

all: $(NAME)

$(NAME) : $(SRC) 
	@gcc -Wall -Wextra -Werror -c -O3 -mcpu=apple-m2 -Isrc \
		-fno-builtin-memset -fno-builtin-memcpy -fno-builtin-bzero \
		-fno-builtin-memmove -fno-builtin-memchr -fno-builtin-strlen \
		-fno-builtin-strdup -fno-builtin-strcpy -fno-builtin-strncpy \
		-fno-builtin-strcat -fno-builtin-strncat -fno-builtin-strlcat \
		-fno-builtin-strchr -fno-builtin-strrchr -fno-builtin-strstr \
		-fno-builtin-strnstr -fno-builtin-strcmp -fno-builtin-strncmp \
		-fno-builtin-atoi $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@find . -name "*.o" -delete

fclean: clean
	@rm -f $(NAME)

re: all clean

rm:
	@rm -f $(OBJ)
	@find . -name "*.o" -delete
	@rm libft.a

build: re clean




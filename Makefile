# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 14:54:00 by tbenoist          #+#    #+#              #
#    Updated: 2025/09/14 21:59:25 by mihaiblandu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MAIN = main

# Find all .c files recursively (excluding main.c)
SRC = $(shell find . -name "*.c" -not -name "main.c" 2>/dev/null)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "✅ Library $(NAME) created successfully!"
	@find . -name "*.o" -delete 2>/dev/null || true

%.o: %.c
	@echo "🔨 Compiling $<..."
	@gcc -Wall -Wextra -Werror -c -O3 $< -o $@

$(MAIN): $(NAME)
	@gcc -Wall -Wextra -Werror -O3 main.c -L. -lft -o $(MAIN)
	@echo "✅ Main program compiled successfully!"

run: $(MAIN)
	@echo "🚀 Running the program..."
	@./$(MAIN)

test: run

debug: $(NAME)
	@gcc -Wall -Wextra -Werror -g main.c -L. -lft -o $(MAIN)_debug
	@echo "🐛 Debug version compiled. Run with: gdb ./$(MAIN)_debug"

valgrind: $(MAIN)
	@echo "🔍 Running valgrind memory check..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(MAIN)

clean:
	@rm -f $(OBJ)
	@rm -f *.o
	@find . -name "*.o" -delete 2>/dev/null || true
	@echo "🧹 Object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(MAIN)
	@rm -f $(MAIN)_debug
	@echo "🧽 All generated files cleaned"

re: fclean all

help:
	@echo "📋 Available targets:"
	@echo "  all       - Build the library $(NAME)"
	@echo "  $(MAIN)       - Build the main program"
	@echo "  run       - Build and run the main program"
	@echo "  test      - Same as run"
	@echo "  debug     - Build debug version with -g"
	@echo "  valgrind  - Run with memory leak detection"
	@echo "  clean     - Remove object files"
	@echo "  fclean    - Remove all generated files"
	@echo "  re        - Clean and rebuild everything"
	@echo "  help      - Show this help message"

.PHONY: all clean fclean re run test debug valgrind help
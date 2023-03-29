# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 09:55:39 by ddyankov          #+#    #+#              #
#    Updated: 2023/03/29 15:48:18 by ddyankov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c checks.c count_size.c sort_operations.c push.c rotate.c \
		reverse_rotate.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		@rm -f $(OBJ)
		@make clean -C libft

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)
re: fclean all

.PHONY:		all clean fclean re

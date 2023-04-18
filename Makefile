# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 09:55:39 by ddyankov          #+#    #+#              #
#    Updated: 2023/04/05 11:13:06 by ddyankov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c checks.c count_size.c swap.c push.c rotate.c \
		reverse_rotate.c small_sort.c find_rank.c big_sort.c free.c \
		start_sorting.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	 @make -C libft
	 
clean:
		@rm -f $(OBJ)
		@make clean -C libft

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)
re: fclean all

.PHONY:		all clean fclean re

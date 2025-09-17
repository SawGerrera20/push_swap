# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 17:21:25 by pgaillar          #+#    #+#              #
#    Updated: 2025/09/12 21:55:41 by pgaillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS_DIR = ./srcs/
OBJS_DIR = ./.objs/
INCLUDES = ./includes/

SRCS = push_swap.c push_swap_utils.c push.c parsing.c \
		utils.c ft_split.c utils_two.c check_input.c sort.c \
		rotate.c reverse_rotate.c swap.c radix.c\

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

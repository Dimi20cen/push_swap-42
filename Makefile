# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 14:22:53 by dmylonas          #+#    #+#              #
#    Updated: 2021/10/01 20:44:46 by dmylonas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME_LIB = ./push_swap.a
NAME = push_swap

CFLAGS = -Wall -Werror -Wextra
SRCS = main.c deallocators.c helper_0.c r_rotate_ops.c rotate_ops.c \
	swap_push_ops.c is_valid_and_convert.c write_ops.c sort.c \
	transform.c is_sorted.c sort_small.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(SRCS)
	gcc $(CFLAGS) $(SRCS) -g -o $(NAME)

# $(NAME_LIB): $(SRCS) $(NAME_LIB)
# 	gcc $(CFLAGS) -c $(SRCS)
# 	ar rc $(NAME_LIB) $(OBJS)
# 	ranlib $(NAME_LIB)
# 	rm -f $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_LIB)

re: fclean all

.PHONY: all clean fclean re
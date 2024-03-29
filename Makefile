# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosman <rosman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 21:43:19 by rosman            #+#    #+#              #
#    Updated: 2024/02/29 21:34:56 by rosman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror # -g3 -fsanitize=address
LIBFTft_printf	= ft_printf/libftprintf.a
AR = ar -rcs
RM = rm -f

SRC =  push_swap.c \
		split.c \
		utils.c \
		functions.c\
		helper.c \
		radix.c \
		sort_three.c \
		sort_four.c \
		sort_five.c \
		sorting.c \
		

OBJS = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJS) $(LIBFTft_printf)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTft_printf) -o $(NAME)

$(LIBFTft_printf):
	make -C ft_printf

clean:
	make clean -C ft_printf
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFTft_printf)

re: clean all

.PHONY: all clean fclean re
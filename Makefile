# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 13:43:29 by hdelaby           #+#    #+#              #
#    Updated: 2017/01/29 12:15:19 by hdelaby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_select
CC= gcc
CFLAGS= -Wall -Wextra -Werror

LIBDIR= libft/
LIBNAME = libft/libft.a
LIBFLAGS= -Llibft -lft -ltermcap

INC= -I./includes -I./libft/includes
INC_PATH= includes
DEPS= ft_select.h

SRC_PATH = src
SRC_NAME = main.c\
		   select_init.c\
		   display.c\
		   select_styling.c\
		   term_config.c\
		   sighandling.c\
		   getters.c\
		   tc_putc.c\
		   ft_getch.c\
		   select_nav.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) 
	@make all -C libft
	@$(CC) $(LIBFLAGS) $(INC) -o $@ $^
	@echo "\033[32m$(NAME) created successfully\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/$(DEPS)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<


clean:
	@rm -rf $(OBJ_PATH)
	@make clean -sC libft

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBNAME)

re: fclean all

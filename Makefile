# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 13:43:29 by hdelaby           #+#    #+#              #
#    Updated: 2017/01/31 10:04:54 by hdelaby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= line_editing
CC= gcc
CFLAGS= -Wall -Wextra -Werror

LIBDIR= libft/
LIBNAME = libft/libft.a
LIBFLAGS= -Llibft -lft -ltermcap

INC= -I./includes -I./libft/includes
INC_PATH= includes
DEPS= line_editing.h\
	  term_config.h

SRC_PATH = src
SRC_NAME = main.c\
		   term_config.c

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

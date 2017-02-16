# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 13:43:29 by hdelaby           #+#    #+#              #
#    Updated: 2017/02/16 11:47:18 by hdelaby          ###   ########.fr        #
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
INC_FILES= line_editing.h\
		   term_config.h\
		   auto_completion.h\
		   history.h\
		   keys.h
DEPS = $(addprefix $(INC_PATH)/, $(INC_FILES))

SRC_PATH = src
SRC_NAME = cursor_motion.c\
		   get_key.c\
		   ft_getwinsz.c\
		   tc_putc.c\
		   main.c\
		   set_term_mode.c

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

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<


clean:
	@rm -rf $(OBJ_PATH)
	@make clean -sC libft

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBNAME)

re: fclean all

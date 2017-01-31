# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 12:49:13 by hdelaby           #+#    #+#              #
#    Updated: 2017/01/21 16:37:47 by hdelaby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = src 
SRC_NAME = ft_memset.c \
		   ft_bzero.c \
		   ft_memcpy.c \
		   ft_memccpy.c \
		   ft_memmove.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   \
		   ft_strlen.c \
		   ft_strdup.c \
		   ft_strcpy.c \
		   ft_strncpy.c \
		   ft_strcat.c \
		   ft_strncat.c \
		   ft_strlcat.c \
		   ft_strchr.c \
		   ft_strrchr.c \
		   ft_strstr.c \
		   ft_strnstr.c \
		   ft_strcmp.c \
		   ft_strncmp.c \
		   \
		   ft_atoi.c \
		   ft_isalpha.c \
		   ft_isdigit.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_toupper.c \
		   ft_tolower.c \
		   \
		   \
		   ft_memalloc.c \
		   ft_memdel.c \
		   \
		   ft_strnew.c \
		   ft_strdel.c \
		   ft_strclr.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_strequ.c \
		   ft_strnequ.c \
		   ft_strsub.c \
		   ft_strjoin.c \
		   ft_strtrim.c \
		   ft_strsplit.c \
		   \
		   ft_itoa.c \
		   ft_putchar.c \
		   ft_putstr.c \
		   ft_putendl.c \
		   ft_putnbr.c \
		   ft_putchar_fd.c \
		   ft_putstr_fd.c \
		   ft_putendl_fd.c \
		   ft_putnbr_fd.c \
		   \
		   ft_lstnew.c \
		   ft_lstadd.c \
		   ft_lstdel.c \
		   ft_lstdelone.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   \
		   ft_lstaddback.c \
		   ft_lstsize.c \
		   ft_strndup.c \
		   ft_strlenc.c \
		   ft_iterative_power.c \
		   ft_lstpop.c \
		   ft_lstlastcontent.c \
		   ft_lstremoveif.c \
		   ft_strnjoin.c \
		   ft_nbrlen.c \
		   ft_isupper.c \
		   ft_putnbrll_str.c \
		   ft_strrev.c \
		   ft_uitoa_base.c \
		   ft_strcnew.c \
		   ft_strfreejoin.c \
		   ft_utf8_encode.c \
		   ft_putunicode.c \
		   ft_wcslen.c \
		   ft_wcs_nbchar.c \
		   ft_putwstr.c \
		   ft_printf.c \
		   get_next_line.c \
		   ft_build_path.c \
		   ft_extract_fname.c \
		   ft_get_ftype.c \
		   ft_is_parent_dir.c \
		   ft_lstbubsort.c \
		   ft_lstrev.c \
		   ft_max.c\
		   ft_lstcpy.c\
		   ft_tablen.c\
		   ft_tab_to_lst.c\
		   ft_lst_to_tab.c\
		   ft_tabdel.c\
		   ft_lstdelstr.c\
		   ft_puttab.c\
		   ft_putlst.c\
		   ft_lstfind.c\
		   ft_isdir.c\
		   ft_tabjoin.c\
		   \
		   ft_dlstnew.c\
		   ft_dlstgethead.c\
		   ft_dlstgettail.c\
		   ft_dlstadd.c\
		   ft_dlstaddback.c\
		   ft_dlstremoveif.c\
		   ft_dlstremovenode.c

PRINTF_SRC = format_int.c\
			 handle_caps.c\
			 handle_int.c\
			 handle_string.c\
			 format_width.c\
			 handle_char.c\
			 handle_date.c\
			 handle_ptr.c\
			 parse_format.c

OBJS = $(SRC_NAME:.c=.o)
OBJS_PRINTF = $(PRINTF_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_PRINTF)
	@$(AR) -rcs $(NAME) $?
	@echo "\033[32m$(NAME) created successfully\033[0m"

%.o: src/%.c
	@$(CC) -c -o $@ $< -I includes/ $(CFLAGS)

%.o: src_printf/%.c 
	@$(CC) -c -o $@ $< -I includes/ $(CFLAGS)

clean:
	@rm -f $(OBJS) $(OBJS_PRINTF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

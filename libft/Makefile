# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruijia <ruijia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 19:48:48 by ruijia            #+#    #+#              #
#    Updated: 2025/03/13 21:53:19 by ruijia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    = libft.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

# Si tus archivos fuente están en un directorio "src", descomenta las siguientes líneas:
# SRC_DIR = src
# OBJ_DIR = obj
# SRCS    = $(wildcard $(SRC_DIR)/*.c)
# OBJS    = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS)

# Si tus archivos fuente están en el mismo directorio que el Makefile, usa:
SRCS    = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
          ft_memcmp.c ft_strlen.c ft_strdup.c\
          ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
          ft_strtrim.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
          ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_itoa.c \
		  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
		  ft_striteri.c ft_strjoin.c ft_strlcpy.c ft_strmapi.c  ft_substr.c \
		  ft_printf.c print_c.c print_d.c print_p.c print_s.c print_u.c\
		  print_x.c print_x_upper.c

OBJS    = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			 ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/17 03:58:02 by smlkshk           #+#    #+#              #
#    Updated: 2021/10/17 03:58:03 by smlkshk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_FILES = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

SRC_BONUS = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstmap.c \
		ft_lstsize.c

OBJ_SRC = $(SRC_FILES:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ_D =	$(SRC_FILES:.c=.d) $(SRC_BONUS:.c=.d)

CC = gcc

REM = rm -f

LIBH = libft.h

FLAGS = -Wall -Wextra -Werror -MMD

all: $(NAME)

$(NAME): $(OBJ_SRC)
			@ar rc $(NAME) $(OBJ_SRC)
			@ranlib $(NAME)

.c.o:
	@$(CC) $(FLAGS) -c $< -o ${<:.c=.o} -I $(LIBH)

bonus: $(OBJ_SRC) $(OBJ_BONUS)
			@ar rc $(NAME) $(OBJ_SRC) $(OBJ_BONUS)
			@ranlib $(NAME)

clean:
	@$(REM) $(OBJ_SRC) $(OBJ_BONUS) $(OBJ_D)
	@echo "Clean status: Success!"

fclean: clean
	@$(REM) $(NAME)
	@echo "Full clean status: Success!"

re: fclean all

.PHONY: all bonus clean fclean re

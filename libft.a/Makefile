# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/20 15:07:40 by sboukhel          #+#    #+#              #
#    Updated: 2026/09/04 23:46:19 by sboukhel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
NAME_BONUS = libft.a
SRCS = ft_atoi.c \
		ft_isalpha.c \
		ft_memchr.c \
		ft_memset.c \
		ft_strlcpy.c \
		ft_strrchr.c \
		ft_bzero.c \
		ft_isascii.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_substr.c \
		ft_calloc.c \
		ft_isdigit.c \
		ft_memcpy.c \
		ft_strdup.c \
		ft_strncmp.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_toupper.c
BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS =$(BONUS:.c=.o)

CC = gcc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror

all : $(NAME)
bonus : $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

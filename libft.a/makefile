# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/20 15:07:40 by sboukhel          #+#    #+#              #
#    Updated: 2026/08/20 15:08:08 by sboukhel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c/
		ft_isalpha.c/
		ft_memchr.c/
		ft_memset.c/
		ft_strlcpy.c/
		ft_strrchr.c/
		ft_bzero.c/
		ft_isascii.c/
		ft_memcmp.c/
		ft_strchr.c/
		ft_strlen.c/
		ft_substr.c/
		ft_calloc.c/
		ft_isdigit.c/
		ft_memcpy.c/
		ft_strdup.c/
		ft_strncmp.c/
		ft_tolower.c/
		ft_isalnum.c/
		ft_isprint.c/
		ft_memmove.c/
		ft_strlcat.c/
		ft_strnstr.c/
		ft_toupper.c/
OBJS = $(SRCS: .c=.o)

CC = gcc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

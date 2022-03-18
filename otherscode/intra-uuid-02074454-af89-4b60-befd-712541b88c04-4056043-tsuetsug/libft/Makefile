# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 16:27:05 by tsuetsug          #+#    #+#              #
#    Updated: 2022/03/12 14:21:29 by tsuetsug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			= ft_memset.c ft_memcpy.c ft_memccpy.c ft_atoi.c ft_bzero.c \
			ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
			ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strlcpy.c \
			ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_strmapi.c ft_split.c ft_itoa.c \
			ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I.
RM				= rm -f

all:			$(NAME)

$(NAME):
				gcc $(CFLAGS) -c $(SRCS)
				ar rc ${NAME} *.o

clean:
				$(RM) *.o

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			clean fclean all re

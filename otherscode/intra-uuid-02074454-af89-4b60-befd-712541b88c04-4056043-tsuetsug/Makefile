# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 14:06:28 by tsuetsug          #+#    #+#              #
#    Updated: 2022/06/08 11:48:58 by ryoakira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BGREEN	= \033[0;32m
OFF		= \033[0m

NAME	= so_long

SRCS	= srcs/so_long.c srcs/import_file.c srcs/so_long_utils.c \
			srcs/import_file_error.c srcs/key_control.c srcs/destroy_window.c
OBJ		= so_long.o import_file.o so_long_utils.o \
			import_file_error.o key_control.o destroy_window.o
HEADERS	= includes/so_long.h
LIBFT	= libft/libft.a
PRINT_F = ft_printf/libftprintf.a
MINILIB = minilibx/libmlx.dylib

CC		= cc
CC_FLAGS= -Wall -Wextra -Werror
RM		= rm -f

all:	$(NAME)

$(NAME): $(SRCS) $(0BJ) $(LIBFT) $(PRINT_F) $(MINILIB)
#	@echo "$(BWHITE)Compiling so_long...$(OFF)"
	$(CC) $(CC_FLAGS) -c $(SRCS) -I $(HEADERS)
	cp minilibx/libmlx.dylib ./
	$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT) $(PRINT_F) -L./minilibx -lmlx -o $(NAME)
#	@echo "$(BGREEN)so_long build completed.$(OFF)"

$(LIBFT):
	@make -C libft

$(PRINT_F):
	@make -C ft_printf

$(MINILIB):
	@make -C minilibx

clean:
	@echo "$(BWHITE)Removing object-files...$(OFF)"
	$(RM) $(OBJ)
	@make clean -C libft
	@make clean -C ft_printf
	@echo "$(BGREEN)Clean done.$(OFF)"

fclean:	clean
	@echo "$(BWHITE)Removing object-files and binary-files...$(OFF)"
	$(RM) $(NAME)
	${RM} libmlx.dylib
	@make clean -C minilibx
	@make fclean -C libft
	@make fclean -C ft_printf
	@echo "$(BGREEN)Fclean done.$(OFF)"

re:		fclean all

.PHONY:		all clean fclean re

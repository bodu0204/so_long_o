CC			= 	cc
CFLAGS 		= -Werror -Wextra -Wall
NAME		= 	so_long
INCLUDES	= 	includes

LIBFT_PATH	= 	./libft/
SRCS_PATH	= 	./srcs/
MLX_PATH	= 	./minilibx_mms/


SRCS_FILES	= 	$(SRCS_PATH)main.c $(SRCS_PATH)map.c $(SRCS_PATH)get_next_line.c $(SRCS_PATH)get_next_line_utils.c \
				$(SRCS_PATH)read_map.c $(SRCS_PATH)assign_image_to_window.c $(SRCS_PATH)event.c \
				$(SRCS_PATH)free.c

SRCS_OBJS	= 	$(SRCS_FILES:.c=.o)

LIBFTMAKE	= 	$(MAKE) -C $(LIBFT_PATH)
LIBFTFLAG	= 	-L$(LIBFT_PATH) -lft
MLXMAKE		= 	$(MAKE) -C $(MLX_PATH)
MLXFLAG	=	-lmlx -framework OpenGL -framework AppKit


all:	$(NAME)

$(MLX_PATH):
		$(GITMLX)

$(NAME):	$(MLX_PATH) $(SRCS_OBJS)
		$(LIBFTMAKE)
		$(MLXMAKE)
		$(CC) $(CFLAGS) $(SRCS_OBJS) $(LIBFTFLAG) $(MLXFLAG) -o $(NAME)

lib:
		$(LIBFTMAKE)

mlx:
		$(MLXMAKE)

.c.o:
		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
		$(LIBFTMAKE) clean
		$(MLXMAKE) clean
		$(RM) $(SRCS_OBJS)

fclean:	clean
		$(LIBFTMAKE) fclean
		$(RM) $(MLX_PATH)/libmlx.a
		$(RM) $(NAME) $(SRCS_OBJS)

re:		fclean all

.PHONY:	all clean fclean lib mlx re

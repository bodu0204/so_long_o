PROJECT_NAME = so_long
NAME		= $(PROJECT_NAME)
BONUSNAME	= checker
SRC			= so_long.c
HEADER		= $(PROJECT_NAME).h
SRC_b		= checker_bonus.c main_bonus.c manipulateA_bnous.c manipulateB_bnous.c util_m_bonus.c
HEADER_b	= checker_bonus.h
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./
PRINTF_GIT	= https://github.com/bodu0204/ftprintf_o.git
PRINTF_od	= ftprintf_o/
PRINTF_d	= libftprintf/
PRINTF_a	= libftprintf.a
MLX			= libmlx.dylib

all : $(NAME)

$(NAME) : genprintf $(HEADER) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(PRINTF_a) $(MLX) -o $(NAME)

bonus : genprintf $(HEADER_b) $(SRC_b)
	$(CC) $(CFLAGS) $(SRC_b) $(PRINTF_a) -o $(BONUSNAME)

newprintf :
	rm -rf $(PRINTF_d)
	git clone $(PRINTF_GIT) $(PRINTF_od)
	cd "$(PRINTF_od)" && make submit
	rm -rf $(PRINTF_od)

genprintf :
	cd "$(PRINTF_d)" && make bonus
	cp $(PRINTF_d)$(PRINTF_a) ./

push : fclean
	git add .
	git commit --allow-empty -m "commit form makefile"
	git push

clean :
	cd "$(PRINTF_d)" && make clean
	rm -f $(PRINTF_a)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUSNAME)
	rm -rf $(PRINTF_od)
	cd "$(PRINTF_d)" && make fclean

re : fclean all

PROJECT_NAME	= so_long
ACHIEV			= $(PROJECT_NAME)
ACHIEVb			= $(ACHIEV)_bonus
SRC_d			= src/
SHA256_d		= sha256_src_bonus/
SRCb_d			= src_bonus/
MINLIBX_d		= minilibx_mms_20200219/
SRC				= end.c game.c key.c map.c map_util.c seting.c so_long.c
SHA256_SRC		= sha256_bonus.c sha256_done_bonus.c sha256_hash_bonus.c sha256_init_bonus.c sha256_utilA_bonus.c sha256_utilB_bonus.c tool_bonus.c
SRCb			= decideP_bonus.c end_win_bonus.c execut_bonus.c game_win_bonus.c map_bonus.c tool_bonus.c decideW_bonus.c errorA_bonus.c execut_util_bonus.c game_win_util_bonus.c map_util_bonus.c window_bonus.c decide_util_bonus.c errorB_bonus.c game_bonus.c key_bonus.c so_long_bonus.c
SHA256_h		= sha256_bonus.h
HEDER			= so_long.h
HEDERb			= so_long_bonus.h
SRC_o			= $(SRC:%.c=%.o)
SHA256_o		= $(SHA256_SRC:%.c=%.o)
SRCb_o			= $(SRCb:%.c=%.o)
MINLIBX			= libmlx.dylib
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -Wshadow -Imlx
LFLAGS			= -Lmlx -lmlx -framework OpenGL -framework AppKit
PRINTF_GIT		= https://github.com/bodu0204/ftprintf_o.git
PRINTF_od		= ftprintf_o/
PRINTF_d		= libftprintf/
PRINTF_a		= libftprintf.a

all : $(ACHIEV)

$(NAME) : all

$(ACHIEV) : $(PRINTF_a) $(SRC_d)$(HEDER) $(addprefix $(SRC_d),$(SRC_o)) $(MINLIBX)
	$(CC) $(addprefix $(SRC_d),$(SRC_o)) $(PRINTF_a) $(MINLIBX) -o $(ACHIEV)

$(ACHIEVb) : $(PRINTF_a) $(SRCb_d)$(HEDERb) $(SHA256_d)$(SHA256_h) $(addprefix $(SRCb_d),$(SRCb_o)) $(addprefix $(SHA256_d),$(SHA256_o)) $(MINLIBX)
	$(CC) $(addprefix $(SRCb_d),$(SRCb_o)) $(addprefix $(SHA256_d),$(SHA256_o)) $(PRINTF_a) $(MINLIBX) -o $(ACHIEVb)

bonus : $(ACHIEVb)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(basename $<).o

$(MINLIBX) :
	cd "$(MINLIBX_d)" && make
	cp -f $(MINLIBX_d)$(MINLIBX) ./

$(PRINTF_d) :
	rm -rf $(PRINTF_d)
	git clone $(PRINTF_GIT) $(PRINTF_od)
	cd "$(PRINTF_od)" && make file
	mv $(PRINTF_od)$(PRINTF_d) ./
	rm -rf $(PRINTF_od)

$(PRINTF_a) : $(PRINTF_d)
	cd "$(PRINTF_d)" && make bonus
	cp $(PRINTF_d)$(PRINTF_a) ./

clean :
	cd "$(PRINTF_d)" && make clean
	cd "$(MINLIBX_d)" && make clean
	rm -f $(addprefix $(CLIENT_d),$(CLIENT_o))
	rm -f $(addprefix $(SERVER_d),$(SERVER_o))
	rm -f $(addprefix $(SHA256_d),$(SHA256_o))
	rm -f $(addprefix $(CLIENTb_d),$(CLIENTb_o))
	rm -f $(addprefix $(SERVERb_d),$(SERVERb_o))
	rm -f $(addprefix $(SHA256b_d),$(SHA256b_o))
	rm -f $(PRINTF_a)

fclean : clean
	rm -f $(ACHIEV)
	rm -f $(ACHIEVb)
	rm -rf $(PRINTF_od)
	cd "$(PRINTF_d)" && make fclean

re : fclean all

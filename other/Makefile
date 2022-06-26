PROJECT_NAME	= so_long
ACHIEV			= $(PROJECT_NAME)
ACHIEVb			= $(ACHIEV)_bonus
SRC_d			= src/
SHA256_d		= sha256_src/
SRCb_d			= src_bonus/
MINLIBX_d		= minilibx_mms_20200219/
SRC				= so_long.c
SHA256_SRC		= sha256.c sha256_done.c sha256_hash.c sha256_init.c sha256_utilA.c sha256_utilB.c tool.c
SRCb			= decideP.c decide_util.c error.c execut_util.c game_win.c key.c map_util.c so_long.c tool.c decideW.c end_win.c execut.c game.c game_win_util.c map.c window.c
SHA256_h		= sha256.h
HEDER			= so_long.h
HEDERb			= so_long.h
SRC_o			= $(SRC:%.c=%.o)
SHA256_o		= $(SHA256_SRC:%.c=%.o)
SRCb_o			= $(SRCb:%.c=%.o)
MINLIBX			= libmlx.dylib
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -Wshadow -Imlx
LFLAGS			= -Lmlx -lmlx -framework OpenGL -framework AppKit
PRINTF_GIT		= https://github.com/bodu0204/ftprintf_o.git
PRINTF_od		= ftprintf_o/
PRINTF_d		= libftprintf/
PRINTF_a		= libftprintf.a

all : $(ACHIEV)

$(NAME) : all

$(ACHIEV) : $(PRINTF_a) $(SRC_d)$(HEDER) $(SHA256_d)$(SHA256_h) $(addprefix $(SRC_d),$(SRC_o)) $(addprefix $(SHA256_d),$(SHA256_o)) $(MINLIBX)
	$(CC) $(addprefix $(SRC_d),$(SRC_o)) $(addprefix $(SHA256_d),$(SHA256_o)) $(PRINTF_a) $(MINLIBX) -o $(ACHIEV)

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

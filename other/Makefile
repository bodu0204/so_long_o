PROJECT_NAME	= so_long
ACHIEV			= $(PROJECT_NAME)
ACHIEVb			= $(ACHIEV)_bonus
SRC_d			= src/
SHA256_d		= sha256_src/
SRCb_d			= src_bonus/
SRC				=
SHA256_SRC		= sha256.c sha256_done.c sha256_hash.c sha256_init.c sha256_utilA.c sha256_utilB.c tool.c
SRCb			=
HEDER			= client.h
HEDERb			= client.h
SRC_o			= $(SRC:%.c=%.o)
SHA256_o		= $(SHA256_SRC:%.c=%.o)
SRCb_o			= $(SRCb:%.c=%.o)
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I./
PRINTF_GIT		= https://github.com/bodu0204/ftprintf_o.git
PRINTF_od		= ftprintf_o/
PRINTF_d		= libftprintf/
PRINTF_a		= libftprintf.a

all : $(ACHIEV)

$(NAME) : all

$(ACHIEV) : $(PRINTF_a) $(SRC_d)$(HEDER) $(SHA256_d)$(SHA256_h) $(addprefix $(SRC_d),$(SRC_o)) $(addprefix $(SHA256_d),$(SHA256_o))
	$(CC) $(CFLAGS) $(addprefix $(CLIENT_d),$(CLIENT_o)) $(addprefix $(SHA256_d),$(SHA256_o)) $(PRINTF_a) -o $(ACHIEV)

$(ACHIEVb) : $(PRINTF_a) $(SERVER_d)$(SERVER_h) $(SHA256_d)$(SHA256_h) $(addprefix $(SERVER_d),$(SERVER_o)) $(addprefix $(SHA256_d),$(SHA256_o))
	$(CC) $(CFLAGS) $(addprefix $(SERVER_d),$(SERVER_o)) $(addprefix $(SHA256_d),$(SHA256_o)) $(PRINTF_a) -o $(ACHIEVb)

bonus : $(ACHIEVb)

$(ACHIEVb) : $(PRINTF_a) $(CLIENTb_d)$(CLIENTb_h) $(SHA256b_d)$(SHA256b_h) $(addprefix $(CLIENTb_d),$(CLIENTb_o)) $(addprefix $(SHA256b_d),$(SHA256b_o))
	$(CC) $(CFLAGS) $(addprefix $(CLIENTb_d),$(CLIENTb_o)) $(addprefix $(SHA256b_d),$(SHA256b_o)) $(PRINTF_a) -o $(ACHIEVb)

$(ACHIEVb) : $(PRINTF_a) $(SERVERb_d)$(SERVERb_h) $(SHA256b_d)$(SHA256b_h) $(addprefix $(SERVERb_d),$(SERVERb_o)) $(addprefix $(SHA256b_d),$(SHA256b_o))
	$(CC) $(CFLAGS) $(addprefix $(SERVERb_d),$(SERVERb_o)) $(addprefix $(SHA256b_d),$(SHA256b_o)) $(PRINTF_a) -o $(ACHIEVb)


.c.o :
	$(CC) $(CFLAGS) -c $< -o $(basename $<).o

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

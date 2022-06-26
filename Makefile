PROJECT_NAME	= so_long
ACHIEV			= $(PROJECT_NAME)
ACHIEVb			= $(ACHIEV)_bonus
ACHIEV+			= libmlx.dylib
SRC_PASS		= src
SRCb_PASS		= src_bonus
OTHER_PASS		= other
SHA256_PASS		= sha256_src
SUBMIT_d		= $(PROJECT_NAME)/
IMG				= img
MINLIBX			= stdsrc/minilibx_mms_20200219
PRINTF_GIT		= https://github.com/bodu0204/ftprintf_o.git
PRINTF_od		= libftprintf_o/
PRINTF_a		= libftprintf.a
PRINTF_d		= libftprintf/
TEST_d			= test_case_0/

all : $(ACHIEV)

$(ACHIEV) : file
	cd "$(SUBMIT_d)" && make all
	cp -f $(SUBMIT_d)$(ACHIEV) ./$(ACHIEV).exe
	cp -f $(SUBMIT_d)$(ACHIEV+) ./

bonus : $(ACHIEVb)

$(ACHIEVb) : file
	cd "$(SUBMIT_d)" && make bonus
	cp -f $(SUBMIT_d)$(ACHIEVb) ./
	cp -f $(SUBMIT_d)$(ACHIEV+) ./

push : fclean
	git add .
	git commit --allow-empty -m "commit form makefile"
	git push

cloneprintf :
	git clone $(PRINTF_GIT) $(PRINTF_od)
	cd "$(PRINTF_od)" && make submit
	rm -rf $(PRINTF_od)

submitfile : push cloneprintf file

submit : outclean submitfile
	mv $(SUBMIT_d) ../

file : fclean cloneprintf
	mkdir $(SUBMIT_d)
	cp -rf $(SRC_PASS) $(SUBMIT_d)
	cp -rf $(SRCb_PASS) $(SUBMIT_d)
	cp -f $(OTHER_PASS)/* $(SUBMIT_d)
	cp -rf $(SHA256_PASS) $(SUBMIT_d)
	mkdir $(SUBMIT_d)$(IMG)
	cp -rf $(IMG)/*.xpm $(SUBMIT_d)$(IMG)
	cp -rf $(MINLIBX) $(SUBMIT_d)
	mv $(PRINTF_d) $(SUBMIT_d)

test : file
	cd "$(SUBMIT_d)" && make all
	cd "$(SUBMIT_d)" && make bonus
	mkdir $(TEST_d)
	cp -f $(SUBMIT_d)$(ACHIEV) $(TEST_d)
	cp -f $(SUBMIT_d)$(ACHIEVb) $(TEST_d)

fclean :
	rm -rf $(SUBMIT_d)
	rm -rf $(PRINTF_d)
	rm -rf $(TEST_d)
	rm -f $(ACHIEV).exe
	rm -f $(ACHIEV+)
	rm -f $(ACHIEVb)

outclean :
	rm -rf ../$(SUBMIT_d)

allclean : fclean outclean

re : fclean all

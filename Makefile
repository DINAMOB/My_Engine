##
## EPITECH PROJECT, 2024
## B-PSU-100-RUN-1-1-mytop-antonie.morel
## File description:
## Makefile
##

include config.mk

HEADER = -I $(HEADER_DIR)

SRC = main$(EXT) \
	$(shell find src/ -name '*$(EXT)')
OBJ = $(SRC:$(EXT)=.o)

FILE :=  $(words $(SRC))
PERCENT = $(shell echo "$$(($(COUNT)*100/$(FILE)))")
COUNT := 0

export MODE = DEBUG
ifeq ($(MODE), DEBUG)
	CFLAGS += -g -ggdb
endif

.PHONY: all clean fclean $(EXEC)

#Rule
all: _mode_info_ _lib_build_ _version_info_ $(EXEC)

$(EXEC): $(OBJ)
	@echo "Executable Linking..."
	@$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(HEADER)
	@echo "\033[32m$(EXEC)\033[0m Build \033[33mcompleted!\033[0m"


clean:
	@make -j --no-print-directory clean -C lib
	@find -name "*~" -delete -o -name "#*#" -delete -o -name "*.o" -delete
	@echo 'Cleaning SRC "*~ / #*# / *.o".'

fclean: clean
	@make -j --no-print-directory fclean -C lib
	@wait
	@echo "Cleaning $(EXEC)."
	@rm -f $(EXEC)

re: fclean all

tests_run:
	@make -j --no-print-directory -C tests/
	@wait

tests_clean:
	@make -j clean --no-print-directory -C tests/
	@wait

tests_fclean:
	@make -j fclean --no-print-directory -C tests/
	@wait

tests_re:
	@make -j re --no-print-directory -C tests/
	@wait

mode:
ifeq ($(MODE), DEBUG)
	@sed -i '20s/DEBUG/RELEASE/' Makefile
	@echo "Current mode: \033[1;42mRELEASE\033[0m"
else
	@sed -i '20s/RELEASE/DEBUG/' Makefile
	@echo "Current mode: \033[1;41mDEBUG\033[0m"
endif

%.o: %$(EXT)
	$(eval COUNT :=  $(shell echo $$(($(COUNT) + 1))))
	@echo "[$(call PERCENT)%] Compiling \033[1m$<\033[0m '$(CFLAGS)'..."
	@$(CC) -c $< -o $@ $(CFLAGS) $(HEADER)

_version_info_:
	@if [ -f $(EXEC) ]; then \
	    for src in $(SRC); do \
	        if [ "$$src" -nt $(EXEC) ]; then \
	            echo "\033[36m$$src\033[0m is newer than '$(EXEC)'."; \
	        fi; \
	    done; \
	fi

_mode_info_:
ifeq ($(MODE), DEBUG)
	@echo "Compiler mode: \033[1;41mDEBUG\033[0m"
else
	@echo "Compiler mode: \033[1;42mRELEASE\033[0m"
endif

_lib_build_:
	@make -j --no-print-directory -C lib/
	@wait

##
## EPITECH PROJECT, 2024
## B-CPE-100-RUN-1-1-cpoolday13-antonie.morel
## File description:
## Makefile
##

include ./../config.mk

HEADER = -I ../$(HEADER_DIR)

SRC = $(shell find ./ -name '*$(EXT)')
OBJ = $(SRC:$(EXT)=.o)

FILE :=  $(words $(SRC))
PERCENT = $(shell echo "$$(($(COUNT)*100/$(FILE)))")
COUNT := 0

ifeq ($(MODE), DEBUG)
	CFLAGS += -g -ggdb
endif

.PHONY: all clean fclean $(LIB)

#Rule
all: _version_info_ $(LIB)

$(LIB): $(OBJ)
	@echo "LIB Linking..."
	@ar rc -o $@ $^
	@echo "LIB Build \033[33mcompleted!\033[0m"

clean:
	@find -name "*~" -delete -o -name "#*#" -delete -o -name "*.o" -delete
	@echo 'Cleaning LIB "*~ / #*# / *.o".'

fclean:
	@rm -f $(LIB)

re: fclean all

%.o: %$(EXT)
	$(eval COUNT :=  $(shell echo $$(($(COUNT) + 1))))
	@echo "[$(call PERCENT)%] Compiling \033[1m$<\033[0m '$(CFLAGS)'..."
	@$(CC) -c $< -o $@ $(CFLAGS) $(HEADER)

_version_info_:
	@if [ -f $(LIB) ]; then \
	    for src in $(SRC); do \
	        if [ "$$src" -nt $(LIB) ]; then \
	            echo "\033[36m$$src\033[0m is newer than '$(LIB)'."; \
	        fi; \
	    done; \
	fi

##
## EPITECH PROJECT, 2025
## B-MUL-100-RUN-1-1-myradar-antonie.morel
## File description:
## config
##

#Executable name def
EXEC = corewar
LIB = libperso.a
UNIT_TESTS = unit_tests

#Compiler
CC = g++

EXT = .cpp

#Header def
HEADER_DIR = include

SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CFLAGS = -Wall -Werror -Wextra
GL_FLAGS = -lGL -lGLU
LDFLAGS = -L lib -lperso $(SFML) $(GL_FLAGS)

EXCLUDE = --exclude=lib/lib_file \
	--exclude=lib/lib_malloc \
	--exclude=lib/lib_my \
	--exclude=lib/lib_printf

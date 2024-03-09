IDIR = include/
LDIR = lib/
SDIR = src/
CC = gcc

INCLUDES = $(wildcard *.h)
SOURCES = $(wildcard $(SDIR)*.c)

main: $(INCLUDES) $(SOURCES) main.c
	$(CC) -I$(IDIR) $^ -o $@
IDIR = include/
LDIR = lib/
SDIR = src/
CC = gcc

INCLUDES = $(IDIR)entity.h $(IDIR)game.h $(IDIR)items.h $(IDIR)map.h $(IDIR)player.h $(IDIR)playeractions.h 
SOURCES = $(SDIR)entity.c $(SDIR)game.c $(SDIR)items.c $(SDIR)map.c $(SDIR)player.c $(SDIR)playeractions.c 

main: $(INCLUDES) $(SOURCES) main.c
	$(CC) -I$(IDIR) $^ -o main.exe

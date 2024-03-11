#ifndef MAP_H
#define MAP_H

#include <items.h>
#include <player.h>
#include <time.h>

// max map size
#define COLS 100
#define ROWS 100

#define GROUND .
#define WALL #



typedef struct {
  char symbol;
  Item* item;
} Tile;

typedef struct {
  Tile tiles[ROWS][COLS];
  
} Map;

void PrintMap(Map map, Player player);
int InitTiles(Map* map, Item (*item)[], int (*itemMap)[2], int itemWeight);

// finish these
void FreeTile();
void UnloadMap();

#endif
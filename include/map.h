#ifndef MAP_H
#define MAP_H

#include <items.h>
#include <player.h>
#include <time.h>

// max map size
#define COLS 4
#define ROWS 4



typedef struct {
  char symbol;
  Item* item;
} Tile;

typedef struct {
  Tile tiles[ROWS][COLS];
  
} Map;

void PrintMap(Map map, Player player);
int InitTiles(Map* map, Item (*item)[], int (*itemMap)[2], int itemWeight);
int InitItems(int (*itemMap)[2], Item (*item)[]);
int GetItemMap(int (*itemMap)[2], int spawnWeight, int seed);



#endif
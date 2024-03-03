#ifndef MAP_H
#define MAP_H

#include <items.h>
#include <player.h>
#include <time.h>

#define COLS 10
#define ROWS 10



typedef struct {
  char symbol;
  Item* item;
} Tile;

typedef struct {
  Tile tiles[ROWS][COLS];
  
} Map;

void PrintMap(Map map, Player player);
int initTiles(Map* map, Item (*item)[], int (*itemMap)[2], int itemWeight);
int initItems(int (*itemMap)[2], Item (*item)[]);
int getItemMap(int (*itemMap)[2], int spawnWeight, int seed);



#endif
#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <items.h>

#define INVENTORY_MAX 12



typedef struct {
  Item* item;
} Inventory;

typedef struct {
  char symbol;
  int location[2];
  Inventory inventory;
} Player;

// returns pointer to player
Player* playerInit(char symbol, int location[2]);



#endif
#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <items.h>

#define INVENTORY_MAX 12

typedef enum {
    NONE,
    PICK_UP_ITEM,
    MOVING,

} PlayerState;

typedef struct {
  Item* item;
} Inventory;

typedef struct {
  char symbol;
  int location[2];
  Inventory inventory;
  // state
  PlayerState state;
} Player;

// returns pointer to player
Player* PlayerInit(char symbol, int location[2]);
// finish these
int FreePlayer();
int FreeInventory();

#endif
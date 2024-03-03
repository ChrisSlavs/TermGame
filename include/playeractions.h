#ifndef PLAYERACTIONS_H
#define PLAYERACTIONS_H

#include <player.h>
#include <map.h>
#include <items.h>

int PickUpItem(Map* map, int loc[2], Inventory* inventory);
int movePlayer(char userIn, Player* player);

#endif
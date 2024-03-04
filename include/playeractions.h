#ifndef PLAYERACTIONS_H
#define PLAYERACTIONS_H

#include <player.h>
#include <map.h>
#include <items.h>
#include <conio.h>

int PickUpItem(Map* map, int loc[2], Inventory* inventory);
int MovePlayer(char userIn, Player* player);
int DisplayInventory(Inventory* inventory, int page);
int HandleInventory(int pageCount);


#endif
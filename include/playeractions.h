#ifndef PLAYERACTIONS_H
#define PLAYERACTIONS_H

#include <player.h>
#include <map.h>
#include <items.h>
#include <conio.h>
#include <string.h>

// allows player to pick up items
int PickUpItem(Player* player, Map* map, char* message);
// allows player to move
int MovePlayer(Player* player, char userIn, char* message);
int DisplayInventory(Inventory* inventory);
int HandleInventory(Inventory* inventory);


#endif
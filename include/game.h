#ifndef GAME_H
#define GAME_H

#include <conio.h>

#include <items.h>
#include <map.h>
#include <player.h>
#include <playeractions.h>
#define ITEM_WEIGHT 50

// return 0 for invalid move 1 for valid
void HandleState(Player* player, char* message);
int HandleEvents(Player* player, Map* map, char* message);
// finish this
void FreeAll(Map* map, Player* player, Item (*items)[]);

#endif
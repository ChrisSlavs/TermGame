#ifndef GAME_H
#define GAME_H

#include <items.h>
#include <map.h>
#include <player.h>
#include <conio.h>
#include <playeractions.h>
#define ITEM_WEIGHT 50


void HandleEvents(Player* player, Map* map, Inventory* inventory);

#endif
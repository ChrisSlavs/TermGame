#include <player.h>

Player* PlayerInit(char symbol, int location[2]) {
  Player* player = malloc(sizeof(Player));
  player->inventory.item = NULL;

  player->symbol = symbol;
  player->location[0] = location[0];
  player->location[1] = location[1];

  return player;
}



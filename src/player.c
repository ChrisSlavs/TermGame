#include <player.h>

Player* playerInit(char symbol, int location[2]) {
  Player* player = malloc(sizeof(Player));

  player->symbol = symbol;
  player->location[0] = location[0];
  player->location[1] = location[1];

  return player;
}



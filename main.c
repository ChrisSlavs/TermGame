#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif

#ifdef linux
#include <kbhitlinux.c>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <game.h>

///Testing const/////
///TILE SETTINGS///
const int ENTITY_MAX = 128;
const int ITEM_MAX = 128;
const char GROUND = '.';
const char WALL = '#';

////////////// MAIN ////////////////
int main(void) {
  // game state
  int run = 1;
  // map
  Map map;
  // player init
  Player* playerPtr = PlayerInit('@', (int[]){1,2});
  if (playerPtr == NULL) {
    run = 0;
    printf("Player init failed!\n");
  }
  Inventory inventory = {NULL};
  //////////// INIT ////////////////////
  // item generation
  int (*itemMap)[2] = (int(*)[2])malloc(sizeof(int[2]) * ITEM_WEIGHT + 1);
  GetItemMap(itemMap, ITEM_WEIGHT, 44595146);
  for (int i = 0; i < ITEM_WEIGHT; i++) {
    printf("%d , %d\n", itemMap[i][0], itemMap[i][1]);
  }
  Item (*item)[ITEM_WEIGHT] = (Item(*)[])malloc(sizeof(Item) * ITEM_WEIGHT + 1);

  // init map items
  InitItems(itemMap, item);
  // init map tiles
  InitTiles(&map, item, itemMap, ITEM_WEIGHT);

  //////// GAME LOOP ///////////
  
  while(run) {
    // print game screen
    PrintMap(map, *playerPtr);

    // event handler
    HandleEvents(playerPtr, &map, &inventory);
  }

  return 0;
}

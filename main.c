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
const int seed = 44595146;

////////////// MAIN ////////////////
int main(void) {
  
  // game state
  int run = 1;
  // map
  //////////// INIT ////////////////////
  Map map;
  // player init
  Player* playerPtr = PlayerInit('@', (int[]){1,2});
  if (playerPtr == NULL) {
    run = 0;
    printf("Player init failed!\n");
  }
  // item generation
  // always free item map after genning items
  int (*itemMap)[2] = malloc(sizeof(int*) * ITEM_WEIGHT + 1);
  GetItemMap(itemMap, ITEM_WEIGHT, seed, ROWS, COLS);
  Item (*items)[] = malloc(sizeof(Item) * ITEM_WEIGHT + 1);

  // init map items
  InitItems(itemMap, items);
  // init map tiles
  InitTiles(&map, items, itemMap, ITEM_WEIGHT);
  free(itemMap);

  //////// GAME LOOP ///////////
  char message[512] = "";
  while(run) {
    // print game screen
    PrintMap(map, *playerPtr);
    // messaging system based on player state
    HandleState(playerPtr, message);
    memcpy(message, "\0", 512);

    // event handler
    run = HandleEvents(playerPtr, &map, message);
  }
  FreeAll(&map, playerPtr, items);
  return 0;
}

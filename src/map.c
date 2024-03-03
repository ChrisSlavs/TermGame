#include <map.h>

void PrintMap(Map map, Player player) {
  // char to be printed on each tile
  char print;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      Tile tile = map.tiles[i][j];
      int pLoc[2] = {player.location[0], player.location[1]};
      if (pLoc[0] == i && pLoc[1] == j) {
        print = player.symbol;
      } // end if
      else if (tile.item == NULL) {
        print = tile.symbol;
      } // end else if
      else if (tile.item != NULL) {
        print = tile.item->symbol;
      } // end else if
      else {
        print = '?';
      }
      printf("%2c", print);
    } // end inner for
    printf("\n");
  } // end outer for
} // end func

int initTiles(Map* map, Item (*item)[], int (*itemMap)[2], int itemWeight) {
    int success = 1;

    // Initialization of Tile elements
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Tile tile = {'.', NULL};
            map->tiles[i][j] = tile;
        }
    }

    // Associating items with tiles based on itemMap
    for (int i = 0; i < itemWeight; i++) {
        int row = itemMap[i][0];
        int col = itemMap[i][1];

        if (map->tiles[row][col].item == NULL) {
            map->tiles[row][col].item = &(*item)[i];
        } 
        else {
          addItem(&map->tiles[row][col].item, &(*item)[i], i);
        }
    }
  return success;
}

int initItems(int (*itemMap)[2], Item (*item)[]) {
  int success = 1;
  
  int i = 0;
  while (itemMap[i][0] != -1 && itemMap[i][1] != -1) {
    Item* newItem = malloc(sizeof(Item));
    if (newItem != NULL) {
      newItem->symbol = 'P';
      newItem->next = NULL;
    }
    else {
      printf("Failed to initialize item!\n");
      success = 0;
    }
    (*item)[i] = *newItem;
    i++;
  }
  
  return success;
}

// create array of coordinates to gen items
int getItemMap(int (*itemMap)[2], int spawnWeight, int seed) {
  int success = 1;
  // set seed to null in main
  if (!seed) {
    srand(time(NULL));
  }
  else {
    srand(seed);
  }
  
  for (int i = 0; i < spawnWeight; i++) {
    itemMap[i][0] = 0;
    itemMap[i][1] = 0;
  }

  // init sentinel vals
  itemMap[spawnWeight][0] = -1;
  itemMap[spawnWeight][0] = -1;

  if (!itemMap) {
    printf("Error generating item map!\n");
    success= 0;
  }

  for (int i = 0; i < spawnWeight; i++) {
    itemMap[i][0] = rand() % ROWS;
    itemMap[i][1] = rand() % COLS;
  }

  return success;
}

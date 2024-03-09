#include <map.h>

void PrintMap(Map map, Player player) {
  // char to be printed on each tile
  char print;
  printf("\n");
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

int InitTiles(Map* map, Item (*item)[], int (*itemMap)[2], int itemWeight) {
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
          // do not add item id here
          AddItem(&map->tiles[row][col].item, &(*item)[i], -1);
        }
    }
  return success;
}

void FreeTile(Tile* tile) {
  free(tile);
  return;
}

void UnloadMap(Map* map) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      map->tiles[i][j].item = NULL;
      FreeTile(&map->tiles[i][j]);
    }
  }
  return;
}

int InitTilesTwo(Map* map, Item (*item)[], int (*itemMap)[2], int itemWeight) {
    int success = 1;

    // Initialization and assignmnent of Tile elements
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
          // do not add item id here
          AddItem(&map->tiles[row][col].item, &(*item)[i], -1);
        }
    }
  return success;
}
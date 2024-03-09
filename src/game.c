#include <game.h>

int HandleEvents(Player* player, Map* map, char* message) {
  char userIn = ' ';
  player->state = NONE;

    // whitespace padding avoids a newline input error
    printf("Please input next move: ");
    userIn = _getch();
    printf("%c\n", userIn);
    switch (userIn) {
      case 'w':
      case 's':
      case 'a':
      case 'd':
        if(MovePlayer(player, userIn, message)) player->state = MOVING;
        break;
      case 'g':
        if (PickUpItem(player, map, message)) player->state = PICK_UP_ITEM;
        break;
      case '.':
        strcpy(message, "Waiting a turn.");
        break;
      case 'i':
        if (player->inventory.item != NULL) HandleInventory(&player->inventory);
        else strcpy(message, "Inventory empty!");
        break;
      case '~':
        return 0;
        break;
      default:
        strcpy(message, "Invalid key!");
        break;
    }
  return 1;
}

void HandleState(Player* player, char* message) {
  switch (player->state)
  {
  case PICK_UP_ITEM:
    printf("%s: %c", message, player->inventory.item->symbol);
    break;
  default:
    printf("%s", message);
    break;
  }
  printf("\n");
  return;
}

void FreeAll(Map* map, Player* player, Item (*items)[]) {
  // frees all items
  for (int i = 0; i < sizeof(items) / sizeof((*items)[0]); i++) {
    FreeItem(&(*items)[i]);
  }

  //free item array;
  free(items);

  // frees all tiles
  for (int i = 0; i < sizeof(map->tiles) / sizeof(map->tiles[0]); i++) {
    for (int j = 0; sizeof(map->tiles) / sizeof(map->tiles[1]); j++) {
      FreeTile(&map->tiles[i][j]);
    }
  }

  return;
}



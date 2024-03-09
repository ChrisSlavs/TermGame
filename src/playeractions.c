#include <playeractions.h>

int PickUpItem (Player* player, Map* map, char* message) {
  // retun val
  int success = 1;
  // location variable for easier access
  int loc[2] = {player->location[0], player->location[1]};
  // Inventory variable for easier access
  Inventory* inventory = &player->inventory; 

  // add check to make sure invent space is available
  int i = 0;
  Item* node = inventory->item;
  while (node != NULL) {
    i++;
    node = node->next;
  }
  // top of stack item
  Item* worldItem = map->tiles[loc[0]][loc[1]].item;
  // check if full
  if (i >= INVENTORY_MAX) {
    success = 0;
    strcpy(message, "Inventory full!\n");
  }
  else if (worldItem == NULL) {
    success = 0;
    strcpy(message, "There is nothing to pickup!\n");
  }
  else {
    
    Item* worldItemTwo = map->tiles[loc[0]][loc[1]].item->next;

    // take world item and assign it inventory linked list
    // best way to keep track of items in list is to count each time the list is updated
    // adding a counter to the items would require this anyways
    
    // make item on ground point to first item in inventory
    worldItem->next = inventory->item;
    // set the first item in the inventory to what was picked up
    inventory->item = worldItem;
    // notify the player what was picked up
    strcpy(message, "You picked up");
    // first item of tile is now what was the second item
    map->tiles[loc[0]][loc[1]].item = worldItemTwo;
  }
  return success;
}


int MovePlayer(Player* player, char userIn, char* message) {
  int val = 1;
  int move[2] = {0, 0};
  int tempLoc[2] = {0, 0};

  switch (userIn) {
    case 'w':
      move[0] = -1;
      break;
    case 's':
      move[0] = 1;
      break;
    case 'a':
      move[1] = -1;
      break;
    case 'd':
      move[1] = 1;
      break;
  }

  tempLoc[0] = move[0] + player->location[0];
  tempLoc[1] = move[1] + player->location[1];

  if ((tempLoc[0] < ROWS && tempLoc[0] > -1) && (tempLoc[1] < COLS && tempLoc[1] > -1)) {
    player->location[0] = tempLoc[0];
    player->location[1] = tempLoc[1];
  }
  else {
    strcpy(message, "Movement block!");
    val = 0;
  }
  return val;
}

// seperate context handle messaging here
int HandleInventory(Inventory* inventory) {
  // exit func
  int quit = 0;

  const int MENU_SIZE = 6;
  int maxPages = (INVENTORY_MAX + (MENU_SIZE - 1)) / MENU_SIZE;  

  int page = 1;
  Item* items[INVENTORY_MAX] = {NULL};
  Item* item = inventory->item;
  int i = 0;
  do {
      items[i] = item;
      item = item->next;
      i++;
  } while (item != NULL);
  
  // looping variables
  char menu = 'a';
  // user input
  char userIn;

  // index of where to start printing menu
  int start = 0;
  // index of item in items
  int itemIndex = 0;
  do {
    printf("\nPage %d\n", page);
    start = ((page - 1) * MENU_SIZE);
    menu = 'A';
    for (int j = start; (j < (page * MENU_SIZE)) && (j < i); j++) {
      printf("%c] %d\n", menu++, items[j]->itemId);
    } // end for
  
    userIn = _getch();
    // ITEM SELECTION HERE
    if (userIn >= 97 && userIn < 97 + MENU_SIZE) {
      itemIndex = (userIn + ((page - 1) * MENU_SIZE)) - 97;
      printf("\nItemId: %d\n", items[itemIndex]->itemId);
    }
    else if (userIn == '\\' && page > 1) {
      page -= 1;
    } // end elif
    else if (userIn == '/' && page < maxPages && i > MENU_SIZE) {
      page += 1;
    } //end elif
    // quit
    else if (userIn == 'Q' || userIn == 'q') {
      quit = 1;
    }
  } while (!quit);
  return 0;
}



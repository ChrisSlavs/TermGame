#include <playeractions.h>

int PickUpItem (Map* map, int loc[2], Inventory* inventory) {
  // retun val
  int success = 1;

  // add check to make sure invent space is available
  int i = 0;
  Item* node = inventory->item;
  while (node != NULL) {
    printf("Item ID: %d\n", node->itemId);
    i++;
    node = node->next;
  }
  // top of stack item
  Item* worldItem = map->tiles[loc[0]][loc[1]].item;
  if (i >= INVENTORY_MAX) {
    success = 0;
    printf("Your inventory is full\n");
  }
  else if (worldItem == NULL) {
    success = 0;
    printf("There is nothing to pick up\n");
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
    printf("You picked up %c\n\n", worldItem->symbol);
    // first item of tile is now what was the second item
    map->tiles[loc[0]][loc[1]].item = worldItemTwo;
  }
  return success;
}


int MovePlayer(char userIn, Player* player) {
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
    printf("\nMovement blocked!\n");
    val = 0;
  }
  return val;
}


int HandleInventory(Inventory* inventory) {
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
  // quit
  int quit = 0;
  // index of where to start printing menu
  int start = 0;
  // index of item in items
  int itemIndex = 0;
  do {
    start = ((page - 1) * MENU_SIZE);
    printf("start: %d\n", start);
    menu = 'a';
    for (int j = start; (j < (page * MENU_SIZE)) && (j < i); j++) {
      printf("%c, %d\n", menu++, items[j]->itemId);
    }
    printf("DEBUG 1\n");
  
    userIn = _getch();
    printf("Page %d\n", page);
    // ITEM SELECTION HERE
    if (userIn >= 97 && userIn < 97 + MENU_SIZE) {
      itemIndex = (userIn + ((page - 1) * MENU_SIZE)) - 97;
      printf("ItemId: %d\n", items[itemIndex]->itemId);
    }
    else if (userIn == '\\' && page > 1) {
      page -= 1;
    } // end elif
    else if (userIn == '/' && page < maxPages) {
      page += 1;
    } //end elif
    
  } while (!quit);

  return 0;
}



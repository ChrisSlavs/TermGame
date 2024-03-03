#include <playeractions.h>

int PickUpItem (Map* map, int loc[2], Inventory* inventory) {
  // retun val
  int success = 1;

  // add check to make sure invent space is available
  int i = 1;
  Item* node = inventory->item;
  while (node != NULL) {
    node = node->next;
    i++;
  }
  // top of stack item
  Item* worldItem = map->tiles[loc[0]][loc[1]].item;
  if (i >= 12) {
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


int movePlayer(char userIn, Player* player) {
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
    printf("\nMovement blocked!");
    printf("Please enter a new move: ");
    val = 0;
  }
  return val;
}
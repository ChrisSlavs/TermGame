#include <items.h>

// itemId > -1
void AddItem (Item** head, Item* newItem, int itemId) {
  newItem->next = *head;
  if (itemId > -1) {
    newItem->itemId = itemId;
  }
  *head = newItem;
}

int InitItems(int (*itemMap)[2], Item (*item)[]) {
  int success = 1;
  
  int i = 0;
  while (itemMap[i][0] != -1 && itemMap[i][1] != -1) {
    Item* newItem = malloc(sizeof(Item));
    if (newItem != NULL) {
      newItem->symbol = 'P';
      newItem->itemId = i;
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
int GetItemMap(int (*itemMap)[2], int spawnWeight, int seed, int rows, int cols) {
  int success = 1;
  // set seed to null in main
  if (!seed) {
    srand(time(0));
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
    itemMap[i][0] = rand() % rows;
    itemMap[i][1] = rand() % rows;
  }

  return success;
}

void FreeItem(Item* item) {
  item->next = NULL;
  free(item);
}
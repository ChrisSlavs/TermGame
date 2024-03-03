#include <items.h>

void addItem (Item** head, Item* newItem, int itemId) {
  newItem->next = *head;
  newItem->itemId = itemId;

  *head = newItem;
}


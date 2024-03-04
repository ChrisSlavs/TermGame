#include <items.h>

void AddItem (Item** head, Item* newItem, int itemId) {
  newItem->next = *head;
  newItem->itemId = itemId;

  *head = newItem;
}


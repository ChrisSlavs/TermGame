#include <items.h>

// itemId > -1
void AddItem (Item** head, Item* newItem, int itemId) {
  newItem->next = *head;
  if (itemId > -1) {
    newItem->itemId = itemId;
  }

  *head = newItem;
}


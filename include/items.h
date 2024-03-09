#ifndef ITEMS_H
#define ITEMS_H

#include <stddef.h>

typedef enum {
  ARMOR,
  WEAPON,
  SCROLL,
  GOLD

} Type;


typedef enum {
  HEALTH,
  LOUD,
  HEAVY
} Trait;
 
typedef struct {
  char symbol;
  char name[32];
  enum Trait;
  enum Type; 

  // linked list stuff
  struct Item* next;
  int itemId;
  
} Item;

void AddItem (Item** head, Item* newItem, int itemId);
int InitItems(int (*itemMap)[2], Item (*item)[]);
int GetItemMap(int (*itemMap)[2], int spawnWeight, int seed, int rows, int cols);

void FreeItem(Item* item);

#endif

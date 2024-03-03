#ifndef ITEMS_H
#define ITEMS_H

typedef enum Type {
  ARMOR,
  WEAPON,
  SCROLL,
  GOLD

};


typedef enum Trait {
  HEALTH,
  LOUD,
  HEAVY

};

// needs trait/type enum, 
typedef struct {
  char symbol;
  char name[32];
  enum Trait;
  enum Type; 

  // linked list stuff
  struct Item* next;
  int itemId;
} Item;

void addItem (Item** head, Item* newItem, int itemId);


#endif

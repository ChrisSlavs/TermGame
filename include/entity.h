#ifndef ENTITY_H
#define ENTITY_H


typedef struct {
  int health;
  char name[32];

} Enemy;

// finish these
int InitEntity();
int FreeEnemy();

#endif
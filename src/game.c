#include <game.h>

void HandleEvents(Player* player, Map* map, Inventory* inventory) {
  int valMove = 1;
  char userIn = ' ';

  // do while avoids infiite repitition
  do {
    // whitespace padding avoids a newline input error
    if(!valMove) {
      PrintMap(*map, *player);
    }
    printf("Please input next move: ");
    userIn = _getch();
    printf("%c\n", userIn);
    switch (userIn) {
      case 'w':
      case 's':
      case 'a':
      case 'd':
        valMove = MovePlayer(userIn, player);
        break;
      case 'g':
        valMove = PickUpItem(map, (int[]){player->location[0], player->location[1]}, inventory);
        break;
      case '.':
        printf("\nWaiting a turn.");
        break;
      case 'i':
        HandleInventory(DisplayInventory(inventory, 0));
        break;
      default:
        printf("\ninvalid key!\n");
        valMove = 0;
        break;
    }
  } while (!valMove);
}
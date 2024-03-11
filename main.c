#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif

#ifdef linux
#include <kbhitlinux.c>
#endif

#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <game.h>

///Testing const/////
///TILE SETTINGS///
const int ENTITY_MAX = 128;
const int ITEM_MAX = 128;
const int seed = 44595146;

const int noiseTest[500][500];

typedef struct {  
  float x, y;
} vec2;

float interpolate(float a1, float a0, float w);

vec2 GetDistanceVec(vec2 iCoord, vec2 fCoord);
float DotGradient(vec2 grad, vec2 iCoord, vec2 fCoord);

vec2 GetGradient(int seed, vec2 corner);

// no permutation tables for scalability
float Perlin2D(int x, int y, int gridsize, int seed);

////////////// MAIN ////////////////
int main(void) {
  
  // game state
  int run = 1;
  // map
  //////////// INIT ////////////////////
  Map map;
  // player init
  Player* playerPtr = PlayerInit('@', (int[]){1,2});
  if (playerPtr == NULL) {
    run = 0;
    printf("Player init failed!\n");
  }
  // item generation
  // always free item map after genning items
  int (*itemMap)[2] = malloc(sizeof(int*) * ITEM_WEIGHT + 1);
  GetItemMap(itemMap, ITEM_WEIGHT, seed, ROWS, COLS);
  Item (*items)[] = malloc(sizeof(Item) * ITEM_WEIGHT + 1);

  // init map items
  InitItems(itemMap, items);
  // init map tiles
  InitTiles(&map, items, itemMap, ITEM_WEIGHT);
  free(itemMap);

  //////// GAME LOOP ///////////
  char message[512] = "";
  /*
  while(run) {
    // print game screen
    PrintMap(map, *playerPtr);
    // messaging system based on player state
    HandleState(playerPtr, message);
    memcpy(message, "\0", 512);

    // event handler
    run = HandleEvents(playerPtr, &map, message);
  }
  FreeAll(&map, playerPtr, items);
  */
 float val;
  for (int y = 0; y < ROWS; y++) {
    for (int x = 0; x < COLS; x++) {
      val = Perlin2D(x, y, 20, 45648);
      printf("%.2f ", val);
    }
    printf("\n");
  }


  return 0;
}

float interpolate(float a1, float a0, float w) {
  return (a1 - a0) * w + a0;
}

vec2 GetDistanceVec(vec2 iCoord, vec2 fCoord) {
  vec2 dist;
  dist.x = fCoord.x - (float)iCoord.x;
  dist.y = fCoord.y - (float)iCoord.y;

  return dist;
}

float DotGradient(vec2 grad, vec2 iCoord, vec2 fCoord) {
  vec2 dist = GetDistanceVec(iCoord, fCoord);

  return (dist.x * grad.x + dist.y * grad.y);
}

vec2 GetGradient(int seed, vec2 corner) {
  vec2 vector;

  const unsigned w = 8 * sizeof(unsigned);
  const unsigned s = w / 2;
  unsigned a = corner.x, b = corner.y;

  a *= 3284157443; b ^= a << s | a >> w - s;
  b *= 1911520717; a ^= b << s | b >> w - s;
  a *= 2048419325;

  float random = a * (3.14159265 / ~(~0u >> 1));

  vector.x = cos(random * seed); vector.y = sin(random / seed);

  return vector;
}

// no permutation tables for scalability
float Perlin2D(int x, int y, int gridsize, int seed) {
  float ans;

  float gridX = (float)x / (float)gridsize;
  float gridY = (float)y / (float)gridsize;
  vec2 gridWorld = {gridX, gridY};

  vec2 gridId = {(int)gridX, (int)gridY};
  vec2 gridLoc = {gridX - gridId.x, gridY - gridId.y};

  vec2 bL = gridId;
  vec2 bR = {gridId.x + 1, gridId.y};
  vec2 tL = {gridId.x, gridId.y + 1};
  vec2 tR = {gridId.x + 1, gridId.y + 1};

  // dot both gradients
  // interpolate both gradients
  vec2 bLGrad = GetGradient(seed, bL);
  float dBL = DotGradient(bLGrad, bL, gridWorld);
  vec2 bRGrad = GetGradient(seed, bR);
  float dBR = DotGradient(bRGrad, bR, gridWorld);
  float lerpBttm = interpolate(dBR, dBL, gridLoc.x);

  // dot both gradients
  // interpolate both gradients
  vec2 tLGrad = GetGradient(seed, tL);
  float dTL = DotGradient(tLGrad, tL, gridWorld);
  vec2 tRGrad = GetGradient(seed, tR);
  float dTR = DotGradient(tRGrad, tR, gridWorld);
  float lerpTop = interpolate(dTR, dTL, gridLoc.x);
  // interpolate both interpolates
  float lerpFinal = interpolate(lerpTop, lerpBttm, gridLoc.y);

  ans = lerpFinal;

  return ans;
} 
#ifndef LIFE_H
#define LIFE_H

#include <stdbool.h>

bool hasTwoLiveNeighbors(int *board, int index, int size);
bool isAlive(int *grid, int i, int size);
bool shouldDie(int *grid, int i, int size);

#endif

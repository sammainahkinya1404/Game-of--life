#include "life.h"



bool hasTwoLiveNeighbors(int *board, int index, int size)
{
    int count = 0;
    int prev = (index - 1 + size) % size;
    int next = (index + 1) % size;

    if (isAlive(board, prev, size))
    {
        count++;
    }

    if (isAlive(board, next, size))
    {
        count++;
    }

    return count == 2;
}


bool isAlive(int *grid, int i, int size) {
  if (i >= 0 && i < size && grid[i] == 1) {
    return true;
  }
  return false;
}

bool shouldDie(int *grid, int i, int size) {
  int liveNeighbors = 0;
  if (isAlive(grid, i - 1, size)) {
    liveNeighbors++;
  }
  if (isAlive(grid, i + 1, size)) {
    liveNeighbors++;
  }
  if (isAlive(grid, i - size, size)) {
    liveNeighbors++;
  }
  if (isAlive(grid, i + size, size)) {
    liveNeighbors++;
  }
  if (liveNeighbors == 2) {
    return true;
  }
  return false;
}


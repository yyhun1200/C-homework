// Task#1

// #1-1
#include <stdio.h>
#define SQUARE_LENGTH 9

int main(void)
{
  int height, length, width, volume, weight;

  height = SQUARE_LENGTH;
  length = SQUARE_LENGTH;
  width = SQUARE_LENGTH;
  volume = height * length * width;
  weight = (volume + 165) / 166;

  printf("Volume (cubic inches) : %d\n", volume);
  printf("Dimensional weight (pounds) : %d\n", weight);

  return 0;
}
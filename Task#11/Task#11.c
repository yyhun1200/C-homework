#include<stdio.h>
#define MAX_FIGURE_NUM 10

enum _shape {LINE=1, RECT=2};
struct shape
{
  enum _shape shape_name;
  int P1_x;
  int P1_y;
  int P2_x;
  int P2_y;
};

struct shape makeStruct(int command) {
  struct shape result;
  if(command == 1){
    result.shape_name = LINE;
  } else {
    result.shape_name = RECT;
  }
  printf("Put the coordinate of Point1: ");
  scanf(" %d %d", &result.P1_x, &result.P1_y);
  printf("Put the coordinate of Point2: ");
  scanf(" %d %d", &result.P2_x, &result.P2_y);
  return result;
}

void printFigure(struct shape array[], int num) {
  for(int i = 0; i < num; i++) {
    if(array[i].shape_name == LINE){
      printf("Figure %d: a line from (%d, %d) to (%d, %d)\n", i+1, array[i].P1_x, array[i].P1_y, array[i].P2_x, array[i].P2_y);
    } else if(array[i].shape_name == RECT){
      printf("Figure %d: a rectangle from (%d, %d) to (%d, %d)\n", i+1, array[i].P1_x, array[i].P1_y, array[i].P2_x, array[i].P2_y);
    }    
  }
}

int main() {
  int input;
  int figureIndex = 0;
  struct shape figure[MAX_FIGURE_NUM];
  for(;;) {
    printf("Put figure shape (1: LINE, 2:RECT, 0: PRINT): ");
    scanf(" %d", &input);
    if(input != 0) {
      figure[figureIndex] = makeStruct(input);
      figureIndex++;
    } else {
      printFigure(figure, figureIndex);
      return 0;
    }
  }
}

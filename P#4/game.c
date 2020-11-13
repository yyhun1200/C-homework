#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BLOCK_NUM 14
#define BLOCK_ROW 3
#define BLOCK_COLUMN 3
#define BOARD_SIZE 9

// Block
void makePlayerBlock(int block[][3], int num, char playerBlock[][3], int num1, int turn)
{
  for(int row = 0; row < 3; row++){
    for(int column = 0; column < 3; column++){
      if(block[row][column] == 0){
        playerBlock[row][column] = '_';
      } else if(block[row][column] == 1) {
        if(turn == 1) {
          playerBlock[row][column] = 'O';
        } else if(turn == 2) {
          playerBlock[row][column] = '@';
        }
      }
    }
  }
};

void printBlock(char playerBlock[][3], int num, int turn) {
  printf("\nP%d's block:\n", turn);
  printf(" _ _ _ \n");
  for(int i = 0; i< 3; i++){
    printf("|");
    for(int j = 0; j < 3; j++){
      printf("%c|", playerBlock[i][j]);
    }
    printf("\n");
  }
  printf("\nPut Your block (r c) or Rotate (0): ");
};

void makeBlock(char playerBlock[][3], int num, int turn) {
  srand((unsigned int) time(NULL));
  int random = rand() % 14 + 1;
  switch(random) {
    case 1:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,1},
        {0,0,0},
        {0,0,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 2:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,1},
        {1,0,0},
        {0,0,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 3:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,1},
        {0,0,1},
        {0,0,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 4:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,1},
        {0,1,0},
        {0,0,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 5:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {0,1,1},
        {1,1,0},
        {0,0,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 6:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,0},
        {0,1,1},
        {0,0,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 7:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,0},
        {1,1,0},
        {0,0,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 8:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,0,0},
        {1,1,0},
        {1,1,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 9:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {0,1,1},
        {1,1,0},
        {1,0,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 10:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,0},
        {0,1,1},
        {0,1,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 11:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {0,1,1},
        {1,1,0},
        {0,1,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 12:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {0,0,1},
        {1,1,1},
        {1,0,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 13:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,0,0},
        {1,1,1},
        {0,0,1}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
    case 14:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {0,1,0},
        {1,1,1},
        {0,1,0}};
        makePlayerBlock(block, 3, playerBlock, 3, turn);
      break;
    }
  }
};

void rotate(char block[][3], int num) {
  //copy
  char copyBlock[3][3];
  for(int row = 0; row < 3; row++){
    for(int column = 0; column < 3; column++){
      copyBlock[row][column] = block[row][column];
    }
  }

  // rotate
  for(int row = 0; row < 3; row++){
    for(int column = 0; column < 3; column++){
      block[row][column] = copyBlock[2-column][row];
    }
  }
};

// Board
void printBoard(char board[][BOARD_SIZE], int num) {
  printf("   1 2 3 4 5 6 7 8 9\n");
  printf("   _ _ _ _ _ _ _ _ _\n");
  for(int row = 0; row < 9; row++){
    printf("%d |", row+1);
    for(int column = 0; column < 9; column++)
    {
      printf("%c|", board[row][column]);
    }
    printf("\n");
  }
}

int userInput(int *rowPointer, int *columnPointer) {
  scanf("%d", rowPointer);
  if(*rowPointer == 0) //rotate
  {
    //
    return 1;
  }
  else // position
  {
    scanf(" %d", columnPointer);
    // 오류처리 요망(인자 3개 받을때)
    return 2;
  }
}

int position(char board[][BOARD_SIZE], int num, char playerBlock[][BLOCK_COLUMN], int num1, int row, int column, int turn) {
  int error = 0;
  row -= 1;
  column -= 1;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {      
      if(board[row+i][column+j] != '_' && playerBlock[i][j] != '_'){
        error = error + 1;
      }
    }
  }

  if(error == 0) {
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(playerBlock[i][j] != '_')
        {
          board[row+i][column+j] = playerBlock[i][j];
        }
      }
    }
    return 2;
  } else {
    printf("P%d is not able to put the block into (%d,%d).", turn, row+1, column+1);
    return 3;
  }
}

int main() {
  char board[9][9] = {
      "_________",
      "_________",
      "_________",
      "_________",
      "_________",
      "_________",
      "_________",
      "_________",
      "_________"
  };
  int turn = 1;
  int row, column;
  char playerBlock[3][3] = {};

  bool gameFinish = false;

  while(!gameFinish) {
    int command = 0;

    printBoard(board, BOARD_SIZE);
    makeBlock(playerBlock, BLOCK_ROW, turn);
    printBlock(playerBlock, BLOCK_ROW, turn);

    // win or lose

    while(command != 2) {
      command = userInput(&row, &column);
      if(command == 1) { // rotate      
        rotate(playerBlock, BLOCK_ROW);
        printBlock(playerBlock, BLOCK_ROW, turn);
      } else if(command == 2) { // position
        command = position(board, BOARD_SIZE, playerBlock, BLOCK_ROW, row, column, turn);
        printf("\n");
        printBlock(playerBlock, BLOCK_ROW, turn);
      }
    }

    // finish turn
    turn = turn == 1? 2 : 1;
  }
}

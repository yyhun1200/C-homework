#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
  char playerBlock[3][3] = {};
  int turn = 1;  

  printBoard(board, BOARD_SIZE);
  makeBlock(playerBlock, BLOCK_ROW, turn);
  printBlock(playerBlock, BLOCK_ROW, turn);

  // user input

  // position

  turn = turn == 1? 2 : 1;
}

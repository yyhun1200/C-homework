#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BLOCK_NUM 14
#define BLOCK_ROW 3
#define BLOCK_COLUMN 3
#define BOARD_ROW 9
#define BOARD_COLUMN 9

// Block
void makePlayerBlock(int block[][BLOCK_COLUMN], int num, char playerBlock[][BLOCK_COLUMN], int num1, int turn)
{
  for(int row = 0; row < BLOCK_ROW; row++){
    for(int column = 0; column < BLOCK_COLUMN; column++){
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

void printBlock(char playerBlock[][BLOCK_COLUMN], int num, int turn, int mode) {
  printf("\nP%d's block:\n", turn);
  printf(" _ _ _ \n");
  for(int i = 0; i < BLOCK_ROW; i++){
    printf("|");
    for(int j = 0; j < BLOCK_COLUMN; j++){
      printf("%c|", playerBlock[i][j]);
    }
    printf("\n");
  }
  if(mode == 1) {
    printf("P1 fails to put the block. P2 wins!");
    exit(0);
  } else {
    printf("\nPut Your block (r c) or Rotate (0): ");
  }
};

void makeBlock(char playerBlock[][BLOCK_COLUMN], int num, int turn) {
  srand((unsigned int) time(NULL));
  int random = rand() % 14 + 1;
  switch(random) {
    case 1:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,1},
        {0,0,0},
        {0,0,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 2:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,1},
        {1,0,0},
        {0,0,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 3:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,1},
        {0,0,1},
        {0,0,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 4:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,1},
        {0,1,0},
        {0,0,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 5:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {0,1,1},
        {1,1,0},
        {0,0,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 6:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,0},
        {0,1,1},
        {0,0,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 7:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,0},
        {1,1,0},
        {0,0,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 8:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,0,0},
        {1,1,0},
        {1,1,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 9:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {0,1,1},
        {1,1,0},
        {1,0,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 10:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,1,0},
        {0,1,1},
        {0,1,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 11:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {0,1,1},
        {1,1,0},
        {0,1,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 12:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {0,0,1},
        {1,1,1},
        {1,0,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 13:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {1,0,0},
        {1,1,1},
        {0,0,1}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
    case 14:
    {
      int block[BLOCK_ROW][BLOCK_COLUMN] = {
        {0,1,0},
        {1,1,1},
        {0,1,0}};
        makePlayerBlock(block, BLOCK_ROW, playerBlock, BLOCK_ROW, turn);
      break;
    }
  }
};

void rotate(char block[][BLOCK_COLUMN], int num) {
  //copy
  char copyBlock[3][3];
  for(int row = 0; row < BLOCK_ROW; row++){
    for(int column = 0; column < BLOCK_COLUMN; column++){
      copyBlock[row][column] = block[row][column];
    }
  }

  // rotate
  for(int row = 0; row < BLOCK_ROW; row++){
    for(int column = 0; column < BLOCK_COLUMN; column++){
      block[row][column] = copyBlock[2-column][row];
    }
  }
};

// Board
void printBoard(char board[][BOARD_COLUMN], int num) {
  printf("   1 2 3 4 5 6 7 8 9\n");
  printf("   _ _ _ _ _ _ _ _ _\n");
  for(int row = 0; row < BOARD_ROW; row++){
    printf("%d |", row+1);
    for(int column = 0; column < BOARD_COLUMN; column++)
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
    return 2;
  }
}

// game
int position(char board[][BOARD_COLUMN], int num, char playerBlock[][BLOCK_COLUMN], int num1, int row, int column, int turn) {
  int error = 0;
  row -= 1;
  column -= 1;

  for(int i = 0; i < BLOCK_ROW; i++) {
    for(int j = 0; j < BLOCK_COLUMN; j++) {
      if(board[row+i][column+j] != '_' && playerBlock[i][j] != '_'){
        error = error + 1;
      }
    }
  }

  if(error == 0) {
    for(int i = 0; i < BLOCK_ROW; i++) {
      for(int j = 0; j < BLOCK_COLUMN; j++) {
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

int isWin(char board[][BOARD_COLUMN], int num, char playerBlock[][BLOCK_COLUMN], int num1) {
  int playerEmptyCount = 0;
  int boardStartRow, boardStartColumn;
  int count = 0;
  bool match = false;
  char boardSlice[3][3];

  // 원본 보호
  char copyBlock[3][3];
  for(int row = 0; row < BLOCK_ROW; row++){
    for(int column = 0; column < BLOCK_COLUMN; column++){
      copyBlock[row][column] = playerBlock[row][column];
      if(playerBlock[row][column] == '_') {
        playerEmptyCount++;
      }
    }
  }
  int rotateDegree = 0;
  while(rotateDegree != 360) {
    for(boardStartRow = 0; boardStartRow < 7; boardStartRow++) {
      for(boardStartColumn = 0; boardStartColumn < 7; boardStartColumn++) {
        for(int row = 0; row < BLOCK_ROW; row++) {
          for(int column = 0; column < BLOCK_COLUMN; column++) {
            boardSlice[row][column] = board[boardStartRow+row][boardStartColumn+column];
          }
        }
        count = 0;
        for(int row = 0; row < BLOCK_ROW; row++) {
          for(int column = 0; column < BLOCK_COLUMN; column++) {
            if(copyBlock[row][column] != '_' && boardSlice[row][column] == '_') {
              count++; // 블록이 들어갈 수 있음 이게 블록크기에서 empty를 뺀 수가 나오면 들어갈 수 있다.
            }
          }
        }
        if((BLOCK_ROW*BLOCK_COLUMN)-playerEmptyCount == count) {
          match = true;
        }
      }
    }    
    rotate(copyBlock, BLOCK_ROW);
    rotateDegree += 90;
  }
  if(match == false) {
    return 1;
  }
  return 0;
}

// main
int main() {
  char board[BOARD_ROW][BOARD_COLUMN] = {
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
  char playerBlock[BLOCK_ROW][BLOCK_COLUMN] = {};

  while(true) {    
    int command = 0;
    printBoard(board, BOARD_ROW);
    makeBlock(playerBlock, BLOCK_ROW, turn);    

    // win or lose
    int mode = isWin(board, BOARD_ROW, playerBlock, BLOCK_ROW);
    printBlock(playerBlock, BLOCK_ROW, turn, mode);


    while(command != 2) {
      command = userInput(&row, &column);
      if(command == 1) { 
        // rotate block
        rotate(playerBlock, BLOCK_ROW);
        printBlock(playerBlock, BLOCK_ROW, turn, 0);
      } else if(command == 2) { 
        // position block
        command = position(board, BOARD_ROW, playerBlock, BLOCK_ROW, row, column, turn);
        printf("\n");
        if(command == 3) {
          printBlock(playerBlock, BLOCK_ROW, turn, 0);
        }
      }
    }

    // finish turn
    turn = turn == 1? 2 : 1;
  }
}

// P#3
// 사목게임
// 20160892 윤도영

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARDROW 6
#define BOARDCOLUMN 7

void print_board(char array[][BOARDCOLUMN], int num, int turn, int win);
int start_check(char array[][BOARDCOLUMN], int boardnum, int row, int column, int updown, int side);
int check_start_point(char board[][BOARDCOLUMN], int boardnum, int row, int column, int updown, int side, int *rowstart, int *columnstart);
int start_check_draw(char array[][BOARDCOLUMN], int boardnum, int row, int column, int updown, int side);
void check_draw(char board[][BOARDCOLUMN], int boardnum);
int initialization(char array[][BOARDCOLUMN], int num, char mark[], int num2);

int main()
{
  int count = 0;
  int column, row, turn = 1;

  int start[2] = {0, 0};
  int *rowstart = &start[0], *columnstart = &start[1];

  char mark[4] = {'_', 'O', '@', 'X'};
  char board[BOARDROW][BOARDCOLUMN] = {
    {"_______"},
    {"_______"},
    {"_______"},
    {"_______"},
    {"_______"},
    {"_______"}
  };

  // 심판
  initialization(board, BOARDROW, mark, 4);

  // Game Start
  while(true) {
    print_board(board, BOARDROW, turn, 0);
    scanf("%d", &column);
    column -= 1;

    for(row = BOARDROW-1; row >= 0; row--)
    {
      if(board[row][column] == mark[0]) {
        board[row][column] = mark[turn];        
        for(int updown = -1; updown <= 1; updown++) {
          for(int side = -1; side <= 1; side++) {
            if(updown == 0 && side == 0) 
              break;
            count = check_start_point(board, BOARDROW, row, column, updown, side, rowstart, columnstart);
            if(count == 4) {
              print_board(board, BOARDROW, turn, 1);
              exit(0);
            }        
          }
        }
        break;
      }
    }
    check_draw(board, BOARDROW);
    turn = turn == 1 ? 2 : 1;
  }
}

void print_board(char array[][BOARDCOLUMN], int num, int turn, int win)
{
  printf("  1   2   3   4   5   6   7\n");
  for(int i = 0; i < BOARDROW; i++)
  {
    printf("|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|\n", array[i][0], array[i][1], array[i][2], array[i][3], array[i][4], array[i][5], array[i][6]);
  }
  if(win == 0) 
  {
    printf("P1's marker is O, P2's marker is @\n");
    printf("P%d's turn, Enter the column number: ", turn);
  } else if(win == 2){
    printf("Game ended in a draw.\n");
  }
  else
    printf("P%d wins!\n", turn);
}

int start_check(char array[][BOARDCOLUMN], int boardnum, int row, int column, int updown, int side)
{
  if(row + updown < 0 || row+updown >= BOARDROW || column + side < 0 || column + side >= BOARDCOLUMN)
    return 1;
  else if(updown == 0 && side == 0)
    return 1;
  else if(array[row][column] == array[row+updown][column+side])
    return 1 + start_check(array, boardnum, row+updown, column+side, updown, side);
  else
    return 1;
}

void check_draw(char board[][BOARDCOLUMN], int boardnum)
{
  int max = 0;
  for(int row = 0; row < BOARDROW; row++)
  {
    for(int column= 0; column < BOARDCOLUMN; column++)
    {
      for(int updown = -1; updown <= 1; updown++)
      {
        for(int side = -1; side <= 1; side++)
        {
          max = max < start_check_draw(board, boardnum, row, column, updown, side) ? start_check_draw(board, boardnum, row, column, updown, side) : max;
        } 
      }    
    }
  }
  if(max < 4)
  {
    print_board(board, boardnum, 0, 2);
    exit(0);
  }
}

int start_check_draw(char array[][BOARDCOLUMN], int boardnum, int row, int column, int updown, int side)
{  
    if(array[row][column] == 'X')
      return 0;
    else if(row + updown < 0 || row+updown >= BOARDROW || column + side < 0 || column + side >= BOARDCOLUMN)
      return 1;
    else if(updown == 0 && side == 0)
      return 1;
    else if(array[row][column] == array[row+updown][column+side] || array[row+updown][column+side] == '_')
      return 1 + start_check_draw(array, boardnum, row+updown, column+side, updown, side);
    else
      return 1;
}

int check_start_point(char board[][BOARDCOLUMN], int boardnum, int row, int column, int updown, int side, int *rowstart, int *columnstart)
{ 
  int count = 0;
  if(row - updown >= BOARDROW || row - updown < 0 || column - side < 0 || column - side >= BOARDCOLUMN)
  {
    *rowstart = row;
    *columnstart = column; 
    count = start_check(board, boardnum, *rowstart, *columnstart, updown, side);    
  } else if(board[row][column] == board[row-updown][column-side]) {
    *rowstart = row-updown;
    *columnstart = column-side;
    check_start_point(board, boardnum, row-updown, column-side, updown, side, rowstart, columnstart);
  } else {
    *rowstart = row;
    *columnstart = column;    
    count = start_check(board, boardnum, *rowstart, *columnstart, updown, side);
    return count;
  }
}

int initialization(char array[][BOARDCOLUMN], int num, char mark[], int num2)
{
  int column = 0;
  while(true)
  {
    printf("For initialization, add block: ");
    scanf("%d", &column);
    if(column == 0) {
      printf("Game started.\n\n");
      return 0;
    }
    for(int i = 5; i >= 0; i--) {
      if(array[i][column-1] == mark[0]) {
        array[i][column-1] = mark[3];
        break;
      }
    }
  }
}
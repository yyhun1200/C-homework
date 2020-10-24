// P#3
// 사목게임
// 20160892 윤도영

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARDROW 6
#define BOARDCOLUMN 7

void print_board(char array[][7], int num, int turn, int win);
int check_win(char board[][7], int num, int row, int column, int turn);
int check_board(char array[][7], int num, int row, int column, int updown, int side);
int initialization(char array[][7], int num, char mark[], int num2);

int main()
{
  int count = 0;
  int column, row, turn = 1;

  char mark[4] = {'_', 'O', '@', 'X'};
  char board[BOARDROW][BOARDCOLUMN] = {
    {"_______"},
    {"_______"},
    {"_______"},
    {"_______"},
    {"_______"},
    {"_______"}
  };

  initialization(board, BOARDROW, mark, 4);

  while(true) {
    print_board(board, BOARDROW, turn, 0);
    scanf("%d", &column);
    column -= 1;
    for(row = BOARDROW-1; row >= 0; row--)
    {
      if(board[row][column] == mark[0]) 
      {
        board[row][column] = mark[turn];     
        check_win(board, BOARDROW, row, column, turn);
        break;
      }
    }

    turn = turn == 1 ? 2 : 1;
  }
}

// 1.row[3]~[0]까지 각 인덱스를 살펴보고 
// 2.@,O대상으로 자신의 다음 줄이 자신과 같지 않고, 
// 자신의 마크나 _의 합이 4이상인게 하나라도 있다면, 진행
// 4이상 없다면 무승부

int check_win(char board[][7], int num, int row, int column, int turn)
{
  for(int updown = -1; updown < 2; updown++) 
    {
      for(int side = -1; side < 2; side++) 
      {
        int count = check_board(board, BOARDROW, row, column, updown, side);
        if(count == 4) 
        {
          print_board(board, BOARDROW, turn, 1);
          exit(0);
        } 
        else if(count == 3) 
        {
          count = check_board(board, BOARDROW, row, column, -updown, -side);
          if(count == 2) 
          {
            print_board(board, BOARDROW, turn, 1);
            exit(0);
          }
        }
      }
    }
}

void print_board(char array[][7], int num, int turn, int win)
{
  printf("  1   2   3   4   5   6   7\n");
  for(int i = 0; i < 6; i++)
    printf("|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|\n", array[i][0], array[i][1], array[i][2], array[i][3], array[i][4], array[i][5], array[i][6]);
  if(win == 0) 
  {
    printf("P1's marker is O, P2's marker is @\n");
    printf("P%d's turn, Enter the column number: ", turn);
  }
  else
    printf("P%d wins!", turn);
}

int check_board(char array[][7], int num, int row, int column, int updown, int side)
{ 
  // 6 > row + updown > 0 || 7 > column + side > 0
  if(row + updown < 0 || row+updown > 6 || column + side < 0 || column + side>7) // 벽에 닿음
    return 1;
  else if(updown == 0 && side == 0)
    return 1;
  else if(array[row][column] == array[row+updown][column+side])
    return 1 + check_board(array, num, row+updown, column+side, updown, side);
  else    
    return 1;
}

int initialization(char array[][7], int num, char mark[], int num2)
{
  int column = 0;
  while(true)
  {
    printf("For initialization, add block: ");
    scanf("%d", &column);
    if(column == 0) 
    {
      printf("Game started.\n\n");
      return 0;
    }
    for(int i = 5; i >= 0; i--)
    {
      if(array[i][column-1] == mark[0])
      {
        array[i][column-1] = mark[3];
        break;
      }
    }
  }
}



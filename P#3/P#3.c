// P#3
// 사목게임
// 20160892 윤도영

#include <stdio.h>
#include <stdbool.h>

void print_board(char array[][7], int num, int turn, int win);
int check_board(char array[][7], int num, int row, int column, int updown, int side);

int main()
{
  int count = 0;
  int column, turn = 1;
  char mark[4] = {'_', 'O', '@', 'X'};
  char board[6][7] = {
    {"_______"},
    {"_______"},
    {"_______"},
    {"_______"},
    {"_______"},
    {"_______"}
  };

  while(true) {
    print_board(board, 6, turn, 0);
    scanf("%d", &column);

    for(int i = 5; i >= 0; i--)
    {
      if(board[i][column-1] == mark[0]) {
        board[i][column-1] = mark[turn];
        for(int j = -1; j < 2; j++)
        {
          for(int k = -1; k < 2; k++)
          {
            count = check_board(board, 6, i, column-1, j, k); // count를 활용하여 승리조건 
            if(count == 4) {
              print_board(board, 6, turn, 1);
              return 0;
            }
          }
        }
        break;
      }
    }
    turn = turn == 1 ? 2 : 1;
  }
}

void print_board(char array[][7], int num, int turn, int win)
{
  printf("  1   2   3   4   5   6   7\n");
  for(int i = 0; i < 6; i++)
    printf("|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|\n", array[i][0], array[i][1], array[i][2], array[i][3], array[i][4], array[i][5], array[i][6]);
  if(win == 0) {
    printf("P1's marker is O, P2's marker is @\n");
    printf("P%d's turn, Enter the column number: ", turn);
  }
  else
  printf("P%d wins!", turn);
}

int check_board(char array[][7], int num, int row, int column, int updown, int side)
{ 
  // 6 > row + updown > 0 || 7 > column + side > 0
  if(row + updown < 0 || row+updown > 6 || column + side < 0 || column + side>7)
    return 1;
  else if(updown == 0 && side == 0)
    return 1;
  else if(array[row][column] == array[row+updown][column+side])
    return 1 + check_board(array, num, row+updown, column+side, updown, side);
  else
    return 1;
}
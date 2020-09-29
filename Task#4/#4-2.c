// #4-2
#include <stdio.h>

int main(void)
{
  int inputNum;

  printf("Put the value of n: ");
  scanf("%d", &inputNum);

  for(int i = 0; i < inputNum; i++) {
    int asteriskNum;

    for(int j = 1; j <= i+1; j++) {
      printf("%d", j);   
      asteriskNum = inputNum - j;
    }

    for(int k = 1; k <= asteriskNum; k++)
    {
      printf("*");
    }

    printf("\n");
  }
  return 0;
}
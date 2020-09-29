// 20160892 윤도영
// #4-1
#include <stdio.h>

int main(void) 
{
  int inputNum;  
  for(;;) {
    int powedNum = 1;

    printf("Put the value of n: ");
    scanf(" %d",&inputNum);

    if(inputNum == 0) return 0;    
    for(int i = 0; i < inputNum; i++) {      
      powedNum = powedNum * 3;
    }

    printf("3^%d is %d\n", inputNum, powedNum);
  }
  return 0;
}
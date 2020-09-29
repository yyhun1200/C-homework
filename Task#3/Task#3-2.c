// # Task3-2
// 20160892 윤도영
#include <stdio.h>

int main(void) 
{
  short num, digits;

  printf("Enter a number : ");
  scanf("%d", &num);

  if (num > 0 && num < 10000){ // 0이상 9999이하 제한
    if(num < 10) digits = 1;
    else if(num < 100) digits = 2;
    else if(num < 1000) digits = 3;
    else if(num < 10000) digits = 4;
  } else { // 이외 숫자 입력시 종료
    return 0;
  }

  printf("The number %d has %d digits", num, digits);
}
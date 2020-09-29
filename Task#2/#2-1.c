// #2-1 
#include<stdio.h>

int main(void) {
  short num1, num2, num3;

  printf("Put three integers: ");
  scanf("%hd, %hd, %hd", &num1, &num2, &num3);
  printf("The result is %d", num1+num2+num3);
}

// #2-2

// Put three integers: 20000,30000,40000
// The result is 24464

// 이런 결과가 나온 이유는 short형 변수에서 overflow가 발생하였기 때문입니다.
// short형은 크기가 2byte의 크기를 가지고 있기때문에 
// signed short의 경우 -(2^15)-1 ~ +(2^15)-1의 값을 가질 수 있습니다. 
// num1 + num2 + num3의 합은 이 값을 넘어 overflow가 발생하였습니다.
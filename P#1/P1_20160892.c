// P#1
#include<stdio.h>

int main(void) {
  short select = 0;

  printf("Enter the calculator mode (1:Normal, 2:Extended): ");
  scanf("%hd", &select);

  if(select == 1) // Normal Mode start
  {
    // declaration
    int a, b;
    int result = 0;
    char O1;

    // user's input
    printf("Put two integers: ");
    scanf(" %d, %d", &a, &b);

    // Validation
    if(a < 0 || b > 1000) {return 0;}

    printf("Put the operator: ");
    scanf(" %c", &O1);

    if(O1 == '/' && b == 0) // number / 0 -> error
    {
      printf("\nERROR : Division by 0 isn't allowed");
      return 0;
    }
    else
    {
      // convert O1 to operator
      if(O1 == '+') {result = a + b;}
      else if(O1 == '-') {result = a - b;}
      else if(O1 == '*') {result = a * b;}
      else if(O1 == '/') {result = a / b;}
      else {return 0;}
    }
    // Print Normal mode result    
    printf("The result is %d\n", result);
    return 0;
} // Normal mode end.
  else if(select == 2) // extended mode start
  {
    int a, b, c;
    int result = 0;
    char O1, O2;

    printf("Put three integers: ");
    scanf("%d, %d, %d", &a, &b, &c);
    // Validation
    if((a < 0 || b < 0 || c < 0) || (a > 1000 || b > 1000 || c > 1000)) {return 0;}

    printf("Put two operator: ");
    scanf(" %c, %c", &O1, &O2);

    // divide by 0
    if((O1 == '/' && b == 0) ||(O2 == '/' && c == 0)) {
      printf("\nERROR : Division by 0 isn't allowed");
      return 0;
    }
    // 우선순위에 따른 연산
    if(O2 == '*' || O2 =='/') {
      if(O2 == '*') {result = b * c;}
      else if(O2 == '/') {result = b / c;}

      if(O1 == '+') {result += a;}
      else if(O1 == '-') {result -= a;}
      else if(O1 == '*') {result *= a;}
      else if(O1 == '/') {result /= a;}
      else {return 0;}

    } else {
      if(O1 == '+') {result = a + b;}
      else if(O1 == '-') {result = a - b;}
      else if(O1 == '*') {result = a * b;}
      else if(O1 == '/') {result = a / b;}
      else {return 0;}

      if(O2 == '+') {result += c;}
      else if(O2 == '-') {result -= c;}
      else if(O2 == '*') {result *= c;}
      else if(O2 == '/') {result /= c;}
      else {return 0;}
    }
    // Print result
    printf("The result is %d\n", result);
    return 0;
  }
}
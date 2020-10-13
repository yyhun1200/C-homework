#include <stdio.h>

int iadd (int num1, int num2);
int isub (int num1, int num2);
int imul (int num1, int num2);
int idiv (int num1, int num2);

int main (void) 
{
  int a = 20, b = 10;

  printf("ADD: %d\n", iadd(a, b));    /* a+b */
  printf("SUB: %d\n", isub(a, b));    /* a-b */
  printf("MUL: %d\n", imul(a, b));    /* a*b */
  printf("DIV: %d\n", idiv(a, b));    /* a/b */
  
  return 0;

}

int iadd (int num1, int num2)
{
  int result = num1 + num2;
  return result;
}
int isub (int num1, int num2)
{
  int result = num1 - num2;
  return result;
}
int imul (int num1, int num2)
{
  int result = num1 * num2;
  return result;
}
int idiv (int num1, int num2)
{
  int result = num1 / num2;
  return result;
}
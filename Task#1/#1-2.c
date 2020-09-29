// #1-2
#include <stdio.h>

int main(void)
{
  int hour, minute;
  
  printf("Put the hour value: ");
  scanf("%d", &hour);
  printf("Put the minute value: ");
  scanf("%d", &minute);

  printf("The time is %d:%d", hour, minute);
}
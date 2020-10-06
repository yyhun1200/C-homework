#include <stdio.h>

#define N 10

int main(void)
{
  int a[N], i, avg;
  int sum = 0, max = 0;

  printf("Enter %d numbers: ", N);

  for(i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    if(a[i] > max)
      max = a[i];
  }
  for(i = 0; i < N; i++)
    sum += a[i];
  avg = sum / N;
  
  printf("Average is %d\n", avg);
  printf("Max value is %d\n", max);

  return 0;
}
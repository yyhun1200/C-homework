// #Task#7
// 20160892 윤도영

#include<stdio.h>

int get_avgsum(int array[], int num, int *average, int *largest);
void rotate(int *p, int *q, int *r);

int main()
{
  int arr[10] = {10,20,30,40,50,60,70,80,90,100};
  int avg, max;

  get_avgsum(arr, 10, &avg, &max);
  rotate(&arr[2], &arr[3], &arr[4]);

  printf("Array: ");
  for (int i=0; i<10; i++)
    printf("%d ", arr[i]);
  printf ("\nAvg: %d, Max: %d\n", avg, max);

  return 0;
}

// Task#7의 설명에는 평균값과 합을 계산해 포인터를 전달하는 함수라 쓰여있습니다.
// 하지만 전달되는 인수의 변수명은 max이고, 출력 예에도 최댓값인 100이라 쓰여 있어, 
// 평균값과 최댓값을 포인터로 전달하였습니다.
// 합을 계산한 값은 return을 통하여 사용가능하도록 함수를 작성하였습니다.
int get_avgsum(int array[], int num, int *average, int *largest)
{
  int sum = 0;
  *largest = array[0];
  for(int i = 0; i < num; i++)
  {
    if(array[i]>*largest) {
      *largest = array[i];
    }
    sum += array[i];
    *average = sum / num;
  }
  return sum;
}

void rotate(int *p, int *q, int *r)
{  
  int extra = *r;
  *r = *q;
  *q = *p;
  *p = extra;
}
// # Task3-1
// 20160892 윤도영
#include <stdio.h>

#define COUNT_SUBJECT 3

int main(void) 
{
  short math, programming, structure;
  float average;
  const char *grade;

  // input
  printf("Put the discrete math score: ");
  scanf("%hd", &math);
  printf("Put the programming language score: ");
  scanf("%hd", &programming);
  printf("Put the structure score: ");
  scanf("%hd", &structure);

  average = (float)(math + programming + structure) / COUNT_SUBJECT;

  if(average > 95) grade = "A+";
  else if(average > 90) grade = "A0";
  else if(average > 85) grade = "B+";
  else if(average > 80) grade = "B0";
  else if(average > 75) grade = "C+";
  else if(average > 70) grade = "C0";
  else grade = "F";

  // output
  printf("The average score is %.2f and the grade is %s", average, grade);
}
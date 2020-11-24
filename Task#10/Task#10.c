#include <stdio.h>
#include <string.h>

#define ARRAY 10

int main()
{
  FILE *list = fopen("C:\\Users\\Dy\\Desktop\\GitHub\\C homework\\Task#10\\list.txt", "r");

  char wordList[ARRAY][ARRAY];
  int counter[ARRAY] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int i = 0;

  while(fscanf(list, "%s", wordList[i]) != EOF)
  {
    for(int check = 0; check < i; check ++) {
      if(strncmp(wordList[i], wordList[check], ARRAY) == 0) {
        counter[check] = counter[check] + 1;
        strcpy(wordList[i],"");
      }
    }
    if(strncmp(wordList[i], "", 1) == 0) {
      continue;
    } else {
      i++;
    }
  }

  for(int j = 0; j < i; j++)
  {
    printf("%s:", wordList[j]);
    printf(" %d\n", counter[j]);
  }
}
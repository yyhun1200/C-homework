#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define PLANET_NUM 9
#define WORD_LENGTH 10
#define INPUT_MAX_LENGTH 200

char *getString(char *input);
void pharseAndCompare(char *string, char **comparison);
int isPlanet(char **comparison, char *word);

int main(int argc, char *argv[]) {
  char *planets[] = {"Mercury", "Venus", "Earth",
                     "Mars", "Jupiter", "Saturn",
                     "Uranus", "Neptune", "Pluto"};
  char input[INPUT_MAX_LENGTH];

  printf("Enter names: ");
  pharseAndCompare(getString(input), planets);
}

char *getString(char *input) {
  int index = 0;
  char ch;
  while((ch = getchar()) != '\n')
  {
    input[index] = ch;
    index++;
  }
  input[index] = '\0'; 
  return input;
}

void pharseAndCompare(char *string, char **comparison) {
  char *current = string;
  char *start = string;
  char word[WORD_LENGTH];

  while(true)
  {
    if(*current == ' ' || *current == '\0') {
      int i = 0;
      for(;start < current; start++){
        word[i] = *start;
        i++;        
      }
      start++;
      word[i] = '\0';
      isPlanet(comparison, word);
    }
    if(*current == '\0') {
      break;
    }
    current++;
  }
}

int isPlanet(char **comparison, char *word)
{
  for(int i = 0; i < PLANET_NUM; i++)
  {
    if(strncmp(comparison[i], word, WORD_LENGTH) == 0) {
      printf("%s is a planet.\n", word);
      return 0;
    }
  }
  printf("%s is NOT a planet.\n", word);
}
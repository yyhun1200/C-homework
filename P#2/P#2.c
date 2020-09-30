#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand((unsigned)time(0));
    int key = rand()*rand()%1001;   

    /* Fill up with your codes */
    int input;
    int life = 10;

    printf("%d\n", key);
    while(life >= 0) {
        printf("Put your guess: ");
        scanf(" %d", &input);
        if(key == input) {// 정답 조건
            if(life == 10) {
                printf("Feeling lucky! the number was %d\n", key);
                return 0;
            } else if(key == 0 || key == 1000) {
                printf("You got the extreme number! the number was %d\n", key);
                return 0;
            } else {
                printf("Player won! the nuber was %d\n", key);
                return 0;
            }
        }
        else if(input > key) {
            printf("The key is lower than %d\n", input);
        }
        else if(input < key) {
            printf("The key is higher than %d\n", input);
        }
        if(key % input == 0) {
            printf("%d is a multiple of the key\n", input);
        }
        life--;
    }
    printf("Computer won! the number was %d\n", key);
    /* *********************** */  

    return 0;
}
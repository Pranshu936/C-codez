#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int number,guess,nguess=1;
    srand(time(0));
    number=rand()%100+1;
    
    do{
        printf("guess any number between 0-100.\n");
        scanf("%d",&guess);

        if(guess<number){
            printf("Higher number plese.\n");
        }

        else if(guess>number){
            printf("lower number plese.\n");
        }

        else{
            printf("your guess is right \nNO. attempt is %d",nguess);
        }
        nguess++;
    }while(guess!=number);
    return 0;
}
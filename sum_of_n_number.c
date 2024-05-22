#include <stdio.h>

int sum(int n);

int main(){
    int n;
    printf("enter the number");
    scanf("%d",&n);
    sum(n);
    return 0;
}

int sum(int n){
    int total=(n*(n+1))/2;
    printf("the sum of n natural number is %d",total);
    return total;
}

//recursion
#include <stdio.h>

int sum(int num);

int main(){
    int n;
    printf("enter the number");
    scanf("%d",&n);
    printf("%d",sum(n));
    return 0;
}

int sum(int num){
    int total;
   if(num!=0){
    int total=num+sum(num-1);
    return total;
   }
   else{
    return num;
   }
}
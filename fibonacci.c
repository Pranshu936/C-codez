#include <stdio.h>

int main(){
    int t1=0,t2=1,n,nextterm;

    printf("enter the number");
    scanf("%d",&n);

    printf("the Fibonacci series is as follows:\n");
    printf("%d,%d,",t1,t2);

    for(int i=3;i<=n;++i){
        nextterm=t1+t2;
        printf("%d,",nextterm);
        t1=t2;
        t2=nextterm;
    }
    return 0;
}
#include <stdio.h>
void pattern(int n);

int main(){
    int num;
    printf("enter the number");
    scanf("%d",&num);
    pattern(num);
    return 0;
}

void pattern(int n){
    if(n==1){
        printf("* \n");
        return;
    }

    pattern(n-1);
    for(int i=0;i<2*n-1;i++){
        printf("*");
    }
    printf("\n");
}

//rectangle 
#include <stdio.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            printf("+");
        }
        printf("\n");
    }
    return 0;
}

//Hallow rectangle
#include <stdio.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (i == 1 || i == rows || j == 1 || j == cols) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

//inverted pyramid
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

//180 degree rotation
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = n; i > 0; i--) {
        for (int j = 0; j <= n; j++) {
            if (j >= i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

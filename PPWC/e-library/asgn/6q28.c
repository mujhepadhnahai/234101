#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, c;

    printf("Fibonacci series: ");

    if (n >= 1) printf("%d ", a);
    if (n >= 2) printf("%d ", b);

    for (int i = 3; i <= n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    if(fork()==0){
        printf("IN CHILD: \n");
        fibonacci(n);
        printf("CHILD done: \n");

    }else{
        wait(2);
        printf("sabas bete \n");
    }
    
    return 0;
}

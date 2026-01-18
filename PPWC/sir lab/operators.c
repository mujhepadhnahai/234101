#include <stdio.h>
 
int main(){
    int x = 5;
    --x;
    int y = x++;
    printf("x= %d, x= %d \n", x++, x++);

    return 0; 
}
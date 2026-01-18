#include <stdio.h>
#define ROW 2
#define COL 3
void  theory(){
    int x =100;
    int *p;
    p = &x;
    // &x-->address of x
    // x-->value of x
    // p-->address of x 
    // *p--> value of x 
    int **q = &p;
    //q-->address of p
    //*q-->&x
    //**q-->value of x

    // int a[2][3]===> 00 01 02 10 11 12 [logical]
    //                 1  2  3  4  5  6
    //                 [1000,1004,1008,1012,1016,1020]
}
int main(){
    int arr[ROW][COL] = {{1,2,3},{4,5,6}};
    int *pi = &arr[0][0];
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf("%4d",*pi++);
        }
        printf("\n");
    }

    return 0;
}
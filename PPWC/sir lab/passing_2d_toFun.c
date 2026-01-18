#include <stdio.h>
#define ROW 2
#define COL 3

void theory(){
    //int (*p)[COL]=a;
    //p[0]-->1st row of a[][]
    //p[0][0]-->1st element in a[][]

}

void func1(int a[][COL],int n){
    for(int x=0;x<n;x++){
        for(int y=0;y<COL;y++){
            a[x][y];
        }
    }
    return ;
}

void func2(int *p){
    for(int x=0;x<ROW*COL;x++){
        *++p;
    }
}

// void func3(int (*p)[COL]){
//     for(int x=0;x<ROW*COL;x++){
        
//     }
// }

int main(){
    int arr[ROW][COL] = {{1,2,3},{4,5,6}};
    // func1(arr,ROW);
    func2(&arr[0][0]);
    printf("After callingt func: \n");
    for(int x=0;x<ROW;x++){
        for(int y=0;y<COL;y++){
            printf("%4d",arr[x][y]);
        }
        printf("\n");
    }
    return 0;
}
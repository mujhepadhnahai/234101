#include <stdio.h>

void func1(int r,int c, int a[r][c]){
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            a[x][y]++;
        }
    }
    return;
}

void func2(int r, int c, int (*p)[c]){
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            // p[x][y]++;
            // p[y];
            (*p)[y]++;
        }
        p++;
    }
    return;
}

void func3(int r, int c, int *p){
    // for(int x=0;x<r;x++){
    //     for(int y=0;y<c;y++){
    //         (*p)++;
    //         p++;
    //     }
    // }
    for(int x=0;x<r*c;x++){
        (*p)++;
        ++p;
    }
    return;
}

int main(){
    int row=2,col=3;
    int arr[2][3] = {{1,2,3},{4,5,6}};
    // func1(row,col,arr);
    func2(row,col,arr);
    // func3(row,col,arr[0]);
    // func3(row, col, &arr[0][0]);
    printf("After calling func: \n");
    for(int x=0;x<row;x++){
        for(int y=0;y<col;y++){
            printf("%4d",arr[x][y]);
        }
        printf("\n");
    }
    return 0;
}
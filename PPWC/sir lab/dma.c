#include <stdio.h>
#include <stdlib.h>

void * malloc(size_t){
    int *p = (int *)malloc(5*sizeof(int));
    for(int x=0;x<5;x++){
        scanf("%d",&p[x]);
    }
    for(int x=0;x<5;x++){
        printf("%4d",p[x]);
    }
}

void * calloc(size_t,size_t){
    int *q = (int *)calloc(5,sizeof(int));
    for(int x=0;x<5;x++){
        scanf("%d",&q[x]);
    }
    for(int x=0;x<5;x++){
        printf("%4d",q[x]);
    }
}

void * realloc(void *ptr, size_t){
    ptr = (int *)realloc(ptr,10*sizeof(int));
    for(int x=0;x<5;x++){
        scanf("%d",&ptr[x]);
    }
    for(int x=0;x<5;x++){
        printf("%4d",ptr[x]);
    }
}

void free(void *p){
    free(p);
}

int main(){
    // p[0]----> 0 1 2 [1st row, 3 cols]
    // p[1]----> 0 1 2 [2nd row, 3 cols]
    int row=2,col=3;
    int arr[2][3];
    int **p =(int **)malloc(row*sizeof(int *));
    for(int x=0;x<row;x++){
        p[x] = (int *)malloc(col*sizeof(int));
    }
    return 0;
}
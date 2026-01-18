#include <stdio.h>
#include <stdlib.h>

void fun1(int p){
    printf("Updated value: %d\n",++p);
}

void fun2(int a[],int p){
    for(int x=0;x<p;x++){
        printf("\n%d",++a[x]);
    }
}

int main(){
    int arr[10],n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the values: ");
    for(int x=0;x<n;x++){
        scanf("%d",&arr[x]);
    }
    fun1(arr[0]); //call by value
    fun2(arr,n);
    for(int x=0;x<n;x++){
        printf("%d",arr[x]);
    }
    printf("\nAfter function calling, value= %d\n",arr[0]);
    return 0;
}
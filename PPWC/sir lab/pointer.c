#include <stdio.h>

int main(){
    int a = 100;
    char b = 'b';
    float c = 3.14;
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int *p = arr;
    for(int j=0;j<n;j++){
        printf("%d",*p);
        p++;
    }
    printf("\n");
    p = arr+(n-1);
    for(int k=n-1;k>=0;k--){
        printf("%d",*p);
        p--;
    }
    printf("\n");
    int *p1 = arr;
    int *p2 = arr+(n-1);
    while(p1<=p2){
        int temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
    }
    for(int l=0;l<n;l++){
        printf("%d",arr[l]);
    }
    printf("\n");
    int *x;
    char *y;
    float *z;

    x = &a;
    y = &b;
    z = &c;

    printf("&a = %p\n",&a);
    printf("&a=%p\n",x);
    printf("a=%d\n",a);//direct referencing
    printf("a=%d\n",*x);//indirect referencing
    x++;
    printf("&a=%p\n",x);
    printf("Size of x=%zu",sizeof(x));
    printf("&a=%p\n",x++ +2);
    printf("&a=%p\n",x);
    return 0;
}
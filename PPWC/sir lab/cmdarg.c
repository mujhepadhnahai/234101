#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int sum=0;
    if (argc<=1){
        printf("No arguements.\n");
        return 1;
    }
    printf("Value of argc: %d\n",argc);
    for(int x=0;x<argc;x++){
        printf("argv[%d]: %s\n",x,argv[x]);
    }
    for(int x=0;x<argc;x++){
        sum+=atoi(argv[x]);
    }
    printf("Sum=%d\n",sum);
    return 0;
}
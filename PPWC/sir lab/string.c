#include <stdio.h>

int main(){
    char s[][100] = {"APPLE","AAA","BBB","CCC"};
    char *p;
    for(int x=0;x<4;x++){
        fputs(s[x],stdout);
        printf("\n");
    }

    return 0;
}
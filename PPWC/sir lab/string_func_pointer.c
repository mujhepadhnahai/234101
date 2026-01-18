#include <stdio.h>

void func1(int r, int c, char s[r][c]){
    for(int x=0;x<r;x++){
        for(int y=0;s[x][y]!='\0';y++){
            s[x][y]+=32;
        }
    }
    return;
}

void func2(int r, int c, char (*p)[c]){
    for(int x=0;x<r;x++){
        for(int y=0;p[x][y]!='\0';y++){
            p[x][y]-=32;
        }
    }
    return;
}

void func3(int r, int c, char *p){
    for(int x=0;x<r;x++){
        for(int y=0;*(p+x*c+y)!='\0';y++){
            *(p+x*c+y)+=32;
        }   
    }
    // for(int x=0;x<r*c && *(p+x)!='\0';x++){
    //     *(p+x)+=32;
    // }
    return;
}
// void func3(int r, int c, char *p){
//     int total = r * c;
//     for (int i = 0; i < total && *(p + i) != '\0'; i++) {
//         // *(p+i) += 32;
//     }
// }

int main(){
    int row=3,col=100;
    char s[3][100] = {"AAA","BBBB","CCCCC"};
    // func1(row,col,s);
    // func2(row,col,s);
    func3(row,col,s[0]);
    printf("After calling func: \n");
    for(int x=0;x<row;x++){
        fputs(s[x],stdout);
        printf("\n");
    }

    return 0;
}
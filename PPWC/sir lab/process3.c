#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 

int main(){
    pid_t id;
    for(int i=0;i<2;i++){
        if((id=fork())<=0) break;
        if (id=fork()) break;
    }
    getchar();
    return 0;
}
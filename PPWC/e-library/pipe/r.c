#include <stdio.h>
#include <unistd.h>

int main(){
    char buf[30];
    read(0,buf,30);
    printf("message from writer :%s",buf);
    return 0;
}

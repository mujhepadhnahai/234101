#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){

    int fd[2];
    char msg[] = "Hare Krishna";
    char buf[30];

    pipe(fd);

    write(fd[1],msg,sizeof(msg));

    read(fd[0],buf,30);
    printf("message from writer :%s\n",buf);
    return 0;
}

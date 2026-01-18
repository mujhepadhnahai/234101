#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

    
    int fd=open("duptest.txt",O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP);
    printf("File Descriptor: fd=%d\n",fd);
    dup(STDOUT_FILENO);
    close(1);
    dup(fd);
    close(fd);
    write(STDOUT_FILENO,"USP\n",4);
    write(STDOUT_FILENO,"DPOS\n",4);
    return 0;
}




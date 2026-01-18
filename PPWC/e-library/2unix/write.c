#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main(){

    char buf[] = {'q','w','e','r','t'};
    int fd = open("a2.txt",O_WRONLY| O_CREAT| O_APPEND,0777);
    if (fd == -1) {
        perror("Open error");
        return 1;
    }

    ssize_t n=  write(fd,buf,5);
    if(fd==-1){
        perror("Write error");
    }
    else{
        printf("Write %ld bytes\n",n);
    }
    return 0;
}

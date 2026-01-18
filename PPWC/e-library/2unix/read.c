#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main(){

    char buf[1000];
    int fd = open("a.txt",O_RDONLY);

    ssize_t n = read(fd,buf,1000);
    if(fd==-1){
        perror("Read error");
    }
    else{
        printf("Read %ld bytes\n",n);
    }
    return 0;
}
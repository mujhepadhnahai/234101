#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){

    pid_t id;
    int fd[2];
    pipe(fd);
    id = fork();
    

    if(id==0){
        char msg[] = {"papa ajj man kar raha hai golgoppa khane ko...\n"};
        write(fd[1],msg,sizeof(msg));
        _exit;
    }else{
        wait(NULL);
        char Buf[100];
        read(fd[0],Buf,100);
        printf("message from child :%s\n",Buf);

    }
    return 0;
}

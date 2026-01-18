#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if(fork()==0){
        close(fd[1]);
        char buf [100];
        read(fd[0],buf,sizeof(buf));
        printf("child received from parent :%s\n",buf);
    }else{
        close(fd[0]);
        write(fd[1],"Hare krishna\n",14);
    }

    return 0;
}

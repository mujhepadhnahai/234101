#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include<sys/wait.h>

int main(){
    printf("Parent started with pid=%ld",(long)getpid());
    pid_t childpid = fork();
    int status;
    if(childpid<0){
        perror("Fork failed to implented\n");
        exit(1);
    }
    if(childpid==0){
        printf("Child before exec=%ld\n",(long)getpid());
        char *myenv[] = {
            "MYVAR = Hello",
            "USER = G3",
            NULL
        };
        execle("/usr/bin/env","env",NULL,myenv);
        execl("/usr/bin/ls","ls","-l",NULL);
        perror("exec failed\n");
        exit(1);
    }else{
        printf("Parent waiting for child=%ld\n",(long)childpid);
        wait(&status);
        printf("Execution of child finished with signal=%d\n",WEXITSTATUS(status));
    }
    return 0;
}
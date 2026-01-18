//Program to create n childs where n is taken from command line.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    // int n = 5;
    pid_t pid;
    for(int i=1;i<=n;i++){
        pid = fork();
        if(pid==0){
        printf("Child: %d , PID: %d , PPID: %d\n",i,getpid(),getppid());
        return 0;
        }
    }

    for(int i=1;i<=n;i++){
        wait(NULL);
    }
    printf("Parent PID: %d\n",getpid());
    printf("finished");
    return 0;
}
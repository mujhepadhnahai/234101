#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid = fork();
    if(pid==0){
        printf("Child PID= %d\n",getpid());
        while(1);
    }
    else{
        printf("Parent PID= %d\n",getpid());
        // wait(NULL);
        while(1);
    }
    return 0;
}
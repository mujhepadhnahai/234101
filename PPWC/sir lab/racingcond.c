#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<sys/wait.h>

int main(){
    char s1[]="I'm Parent...";
    char s2[]="I'm Child...";
    pid_t childpid = fork();
    if(childpid<0){
        perror("fork failed.");
        exit(1);
    }
    int i=0;
    if(childpid==0){ //child process
        while(s2[i]){
            fprintf(stderr,"%c",s2[i++]);
            sleep(1);
        }
        exit(0);
    }
    //parent process
    while(s1[i]){
            fprintf(stderr,"%c",s1[i++]);
            sleep(1);
        }
    wait(NULL);
    return 0;
}
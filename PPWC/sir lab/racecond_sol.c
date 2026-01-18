#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<sys/wait.h>
#include<semaphore.h>

int main(){
    char s1[]="I'm Parent...\n";
    char s2[]="I'm Child...I'm going to use semaphore...\n";
    sem_t sem;
    sem_init(&sem,1,1);
    pid_t childpid = fork();
    if(childpid<0){
        perror("fork failed.");
        exit(1);
    }
    int i=0;
    if(childpid==0){ //child process
        while(s2[i]){
            sem_wait(&sem);
            fprintf(stderr,"%c",s2[i++]);
            sem_post(&sem);
        }
        exit(0);
    }
    // printf("Break here");
    //parent process
    wait(NULL);
    while(s1[i]){
        sem_wait(&sem);
        fprintf(stderr,"%c",s1[i++]);
        sem_post(&sem);
    }
    return 0;
}
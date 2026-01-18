#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
    char s1[] = "is\n"; //p1
    char s2[] = "very\n"; //p2
    char s3[] = "PPWC\n"; //p3
    char s4[] = "boring\n"; //p4 
    int i=0;
    sem_t sem;
    sem_init(&sem,1,3);
    pid_t pid;
    if(!fork()){
        if(!fork()){
            if(fork()){
                sem_wait(&sem);
                while(s2[i]){
                    fprintf(stderr,"%c",s2[i++]);
                }
                exit(0);
            }
            wait(NULL);
            sem_wait(&sem);
            while(s4[i]){
                fprintf(stderr,"%c",s4[i++]);
            }
            exit(0);
        }
        sem_wait(&sem);
        while(s1[i]){
            fprintf(stderr,"%c",s1[i++]);
        }
        exit(0);
    }
    sem_wait(&sem);
    while(s3[i]){
        fprintf(stderr,"%c",s3[i++]);
    }
    getchar();

}
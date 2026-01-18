#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    sem_t sem;
    if(sem_init(&sem,2,1)<0){
        perror("Semaphore initialization failied!");
        exit(1);
    }
    int val;
    if(sem_getvalue(&sem,&val)<0){
        perror("Semaphore value fetching falied!");
        exit(1);
    }
    fprintf(stdout,"Sem value: %d\n",val);
    if(sem_wait(&sem)<0){
        perror("Semaphore value can't be decremented.");
        exit(1);
    }
    if(sem_getvalue(&sem,&val)<0){
        perror("Semaphore value fetching falied!");
        exit(1);
    }
    fprintf(stdout,"Sem value: %d\n",val);
    if(sem_post(&sem)<0){
        perror("Semaphore value can't be incremented.");
        exit(1);
    }
    if(sem_getvalue(&sem,&val)<0){
        perror("Semaphore value fetching failed.");
        exit(1);
    }
    fprintf(stdout,"Sem value: %d\n",val);
    sem_destroy(&sem);
    fprintf(stdout,"Semaphore destroyed!");
    return 0;
}
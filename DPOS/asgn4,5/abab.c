#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t semA, semB;

void* threadA(void* arg){
    for(int i=0;i<10;i++){
        sem_wait(&semA);
        printf("A");
        sem_post(&semB);
    }
    pthread_exit(NULL);
}

void* threadB(void* arg){
    for(int i=0;i<10;i++){
        sem_wait(&semB);
        printf("B");
        sem_post(&semA);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t tA,tB;
    sem_init(&semA,0,1);
    sem_init(&semB,0,0);
    pthread_create(&tA,NULL,threadA,NULL);
    pthread_create(&tB,NULL,threadB,NULL);
    pthread_join(tA,NULL);
    pthread_join(tB,NULL);
    sem_destroy(&semA);
    sem_destroy(&semB);
    return 0;
}
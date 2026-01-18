#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sX, sY1, sZ, sY2;

void* printX(void* arg) {
    for (int i = 0; i < 4; i++) {
        sem_wait(&sX);
        printf("X");
        printf("X");
        fflush(stdout);
        sem_post(&sY1);
    }
    return NULL;
}

void* printY1(void* arg) {
    for (int i = 0; i < 4; i++) {
        sem_wait(&sY1);
        printf("Y");
        fflush(stdout);
        sem_post(&sZ);
    }
    return NULL;
}

void* printZ(void* arg) {
    for (int i = 0; i < 4; i++) {
        sem_wait(&sZ);
        printf("Z");
        printf("Z");
        fflush(stdout);
        sem_post(&sY2);
    }
    return NULL;
}

void* printY2(void* arg) {
    for (int i = 0; i < 4; i++) {
        sem_wait(&sY2);
        printf("Y");
        fflush(stdout);
        sem_post(&sX);
    }
    return NULL;
}

int main() {
    pthread_t tx, ty1, tz, ty2;

    sem_init(&sX, 0, 1);
    sem_init(&sY1, 0, 0);
    sem_init(&sZ, 0, 0);
    sem_init(&sY2, 0, 0);

    pthread_create(&tx, NULL, printX, NULL);
    pthread_create(&ty1, NULL, printY1, NULL);
    pthread_create(&tz, NULL, printZ, NULL);
    pthread_create(&ty2, NULL, printY2, NULL);

    pthread_join(tx, NULL);
    pthread_join(ty1, NULL);
    pthread_join(tz, NULL);
    pthread_join(ty2, NULL);

    printf("\n");

    return 0;
}

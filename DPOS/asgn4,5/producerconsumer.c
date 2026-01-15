#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 10    

int buffer[N];
int in = 0, out = 0;

sem_t empty, full, mutex;

void *producer(void *arg)
{
    int item;
    for (int i = 0; i < 20; i++)
    {
        item = i + 1;

        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % N;

        sem_post(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *arg)
{
    int item;
    for (int i = 0; i < 20; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);

        item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % N;

        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main()
{
    pthread_t t1, t2;

    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
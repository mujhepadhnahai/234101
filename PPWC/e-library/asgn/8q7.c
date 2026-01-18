#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int shmid;
    int *shared;
    pid_t pid;

    shmid = shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT | 0666);
    shared = shmat(shmid,NULL,0);
    pid = fork();

    if(pid==0){
        *shared = 10;
         printf("Child: Sent number = %d\n", *shared);
         sleep(2);
         printf("Child: Received doubled number = %d\n", *shared);
         shmdt(shared);
    }else{
        sleep(1);
        printf("Parent: Received number = %d\n", *shared);
        *shared = (*shared) * 2;
        printf("Parent: Doubled number sent back = %d\n", *shared);
        shmdt(shared);
    }

}
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    int shmid;
    void *p1, *p2, *p3, *p4;
    struct shmid_ds info;
    
    // Create 10-byte shared memory
    shmid = shmget(IPC_PRIVATE,10,IPC_CREAT | 0666);

    // Attach 4 times
    p1 = shmat(shmid, NULL, 0);
    p2 = shmat(shmid, NULL, 0);
    p3 = shmat(shmid, NULL, 0);
    p4 = shmat(shmid, NULL, 0);

    // Get info from kernel
    shmctl(shmid, IPC_STAT, &info);

    printf("Number of attachments = %ld\n", info.shm_nattch);

    while(1);   // keep alive to check ipcs
}

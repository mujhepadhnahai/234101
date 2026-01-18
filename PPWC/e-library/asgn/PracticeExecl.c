#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    pid_t cpid;
    int status;

    cpid = fork();

    if (cpid == 0) {
        printf("Child executing MulThree...\n");
        execl("./MulThree", "MulThree", "2", "3", "4", NULL);
        perror("execl failed");
        exit(1);
    }
    else{
        wait(NULL);

        printf("Parent: Child PID = %d\n", cpid);
    }

    return 0;
}

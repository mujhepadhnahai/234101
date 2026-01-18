#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// Function to create Figure (a)
void figureA() {
    pid_t p1, p2, p3, p4, p5, p6;

    printf("A-P0: PID=%d PPID=%d\n", getpid(), getppid());

    p1 = fork();                 // P0 -> P1
    if (p1 == 0) {
        printf("A-P1: PID=%d PPID=%d\n", getpid(), getppid());

        p2 = fork();             // P1 -> P2
        if (p2 == 0) {
            printf("A-P2: PID=%d PPID=%d\n", getpid(), getppid());

            p3 = fork();         // P2 -> P3
            if (p3 == 0) {
                printf("A-P3: PID=%d PPID=%d\n", getpid(), getppid());
                while(1);
            }

            p4 = fork();         // P2 -> P4
            if (p4 == 0) {
                printf("A-P4: PID=%d PPID=%d\n", getpid(), getppid());

                p6 = fork();     // P4 -> P6
                if (p6 == 0) {
                    printf("A-P6: PID=%d PPID=%d\n", getpid(), getppid());
                    while(1);
                }
                while(1);
            }

            p5 = fork();         // P2 -> P5
            if (p5 == 0) {
                printf("A-P5: PID=%d PPID=%d\n", getpid(), getppid());
                while(1);
            }
            while(1);
        }
        while(1);
    }
    while(1);
}

// Function to create Figure (b)
void figureB() {
    pid_t p1, p2, p3, p4, p5, p6;

    printf("B-P0: PID=%d PPID=%d\n", getpid(), getppid());

    p1 = fork();                 // P0 -> P1
    if (p1 == 0) {
        printf("B-P1: PID=%d PPID=%d\n", getpid(), getppid());

        p3 = fork();             // P1 -> P3
        if (p3 == 0) {
            printf("B-P3: PID=%d PPID=%d\n", getpid(), getppid());

            p4 = fork();         // P3 -> P4
            if (p4 == 0) {
                printf("B-P4: PID=%d PPID=%d\n", getpid(), getppid());

                p5 = fork();     // P4 -> P5
                if (p5 == 0) {
                    printf("B-P5: PID=%d PPID=%d\n", getpid(), getppid());

                    p6 = fork(); // P5 -> P6
                    if (p6 == 0) {
                        printf("B-P6: PID=%d PPID=%d\n", getpid(), getppid());
                        while(1);
                    }
                    while(1);
                }
                while(1);
            }
            while(1);
        }
        while(1);
    }

    p2 = fork();                 // P0 -> P2
    if (p2 == 0) {
        printf("B-P2: PID=%d PPID=%d\n", getpid(), getppid());
        while(1);
    }

    while(1);
}

int main() {
    figureA();   // Run first tree
    // figureB(); // Run second tree (comment figureA to test this)
    return 0;
}

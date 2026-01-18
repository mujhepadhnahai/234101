#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 

int main(){
    pid_t childpid;
    childpid =fork();
    printf("My PID: %ld , Parent PID: %ld\n", (long)getpid(),(long)getpid());
    getchar();
    
    return 0;
}
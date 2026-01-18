#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define STOPPED 4991
#define CONTINUED 65535

int main(){
    pid_t childpid;
    childpid = fork();
    if(childpid==-1){
        fprintf(stderr,"Unable to Fork!\n");
        exit(-1);
    }
    if(childpid==0){ //child process
        fprintf(stdout,"This is a Child process with PID:%ld and PPID:%ld\n", (long)getpid(),(long)getppid());
        for(int x=0;x<=50;x++){
            printf("x=%d\n",x);
            sleep(2);
        }
        exit(0); //normal termination
    }
    //parent process
    int status;    
    fprintf(stdout, "This is Parent process with PID:%ld and childPID:%ld\n",(long)getpid(),(long)childpid);
    do{
        pid_t returnpid;
        returnpid = waitpid(-1,&status,WUNTRACED | __W_CONTINUED);
        fprintf(stderr,"Returned Status from Child(PID:%ld):%d\n",(long)returnpid,status);
        //Normal termination
        if(WIFEXITED(status)){
            fprintf(stderr,"Child terminated normally.Exit Status:%d\n",WEXITSTATUS(status));
        }
        //Abnormal terminaion(Killed by a signal)
        if(WIFSIGNALED(status)){
            fprintf(stderr,"Child terminated abnormally by a signal. Signal No:%d\n",WTERMSIG(status));
            if(__WCOREDUMP(status)){
                printf("CORE DUMP FILE generated\n");
            }else{
                printf("CORE DUMP FILE not generated\n");
            }
        }
        //Abnormal termination(Stopped by a signal)
        if(WIFSTOPPED(status)){
            fprintf(stderr,"Child stopped by a signal. Stop Signal:%d\n",WSTOPSIG(status));
        }
        //Resumed by a signal
        if(WIFCONTINUED(status)){
            fprintf(stderr,"Child has been reusmed by SIGCONT signal\n");
        }
    }while(STOPPED | CONTINUED);

    return 0;
}
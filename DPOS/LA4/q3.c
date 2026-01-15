#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
// first chield copy content of file 1 to file 2,
// second child will display content of file 2
// 3rd will display sorted content of file 2 in reverse __ORDER_

int main(){
    if(vfork()==0){
        fprintf(stderr,"Child: %d, Parent id: %d\n",getpid(),getppid());
        execl("/usr/bin/cp","cp","file1","file2",NULL);
    }
    sleep(1);
    if(vfork()==0){
        fprintf(stderr,"Child: %d, Parent id: %d\n",getpid(),getppid());
        execl("/usr/bin/cat","cat","file2",NULL);
    }
    sleep(1);
    if(vfork()==0){
        fprintf(stderr,"Child: %d, Parent id: %d\n",getpid(),getppid());
        execl("/usr/bin/sort","sort","-r","file2",NULL);
    }
    sleep(1);
    fprintf(stderr,"All child are completed");
    fprintf(stderr,"Parent id:%d\n",getpid());
    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 

int main(){
    pid_t id;
    for(int i=0;i<5;i++){
        if(i==2){
            if((id=fork())<=0){
                break;
            }
            if((id=fork())<=0){
                break;
            }
        }
        if(id=fork()){
            break;
        }
    }
    getchar();
    return 0;
}
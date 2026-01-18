#include <stdio.h>
#include <unistd.h>

int main(){
    char msg[] = "hello i am derik\n";
    write(1,msg,sizeof(msg));
    return 0;
}

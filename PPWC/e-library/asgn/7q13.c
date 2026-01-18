#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>


int main(){
int fd,fd1,fd2,fd3,dup2ret;
char buf[12];
printf("PID=%ld\n",(long)getpid());
fd=open("6q25.c",O_RDONLY);
fd1=open("6q28.c",O_RDONLY);
fd2=open("7q11.c",O_RDONLY);
close(fd1);
dup2ret=dup2(fd,fd2);
if(dup2ret==-1){
perror("dup2 error");
return 1;
}
printf("Value of fd2=%d\n",fd2);
printf("Dup2 return=%d\n",dup2ret);
scanf("%d",&fd);
return 0;
}
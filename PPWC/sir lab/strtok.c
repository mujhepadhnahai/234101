#include<stdio.h>
#include<string.h>

int main(){
    char str[] = "Rajendra Aryan Sahu";
    char *token;
    printf("Actual String: %s\n",str);
    token = strtok(str," ");
    printf("After tokenization:\n");
    while(token!=NULL){
        printf("%s\n",token);
        token = strtok(NULL," ");
    }
    return 0;
}
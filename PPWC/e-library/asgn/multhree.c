#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: %s num1 num2 num3\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    printf("Multiply result: %d\n", a * b * c);

    return 0;
}

---------------------------palendrom----------------------------------
#include <stdio.h>

int main() {
    int n, rev = 0, rem, temp;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while (n != 0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }

    if (temp == rev)
        printf("Palindrome number\n");
    else
        printf("Not a palindrome number\n");

    return 0;
}



----------------------------------------------prime----------------------
#include <stdio.h>

int main() {
    int n, i, count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (n % i == 0)
            count++;
    }

    if (count == 2)
        printf("Prime number\n");
    else
        printf("Not a prime number\n");

    return 0;
}
------------------factorial-----------------------------
#include <stdio.h>

int main() {
    int n, i;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        fact = fact * i;
    }

    printf("Factorial = %lld\n", fact);

    return 0;
}


#include <stdio.h>

int main() {
    int a, b, temp;

    printf("Enter first numbers: ");
    scanf("%d", &a);

    printf("Enter second numbers: ");
    scanf("%d", &b);

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    printf("GCD is: %d", a);
}

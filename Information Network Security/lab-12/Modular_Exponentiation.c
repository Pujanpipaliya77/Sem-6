#include <stdio.h>

int main() {
    int base, exponent, modulus;
    int result = 1;
    int i;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    printf("Enter modulus: ");
    scanf("%d", &modulus);

    for(i = 1; i <= exponent; i++) {
        result = (result * base) % modulus;
    }

    printf("Result = %d", result);
}

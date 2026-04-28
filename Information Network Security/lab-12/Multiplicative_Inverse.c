#include <stdio.h>

int main() {
    int a, n;

    printf("Enter number: ");
    scanf("%d", &n);
    
    printf("Enter modulo: ");
    scanf("%d", &a);

    for(int i = 1; i < a; i++) {
        if((n * i) % a == 1) {
            printf("Multiplicative inverse is: %d", i);
            return 0;
        }
    }

    printf("Inverse does not exist");
}

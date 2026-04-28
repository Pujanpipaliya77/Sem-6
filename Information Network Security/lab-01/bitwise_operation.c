#include <stdio.h>
int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int and_result = a & b;
    int or_result = a | b;
    int xor_result = a ^ b;
    int not_a = ~a;
    int not_b = ~b;

    printf("Bitwise AND (a & b): %d\n", and_result);
    printf("Bitwise OR (a | b): %d\n", or_result);
    printf("Bitwise XOR (a ^ b): %d\n", xor_result);
    printf("Bitwise NOT (~a): %d\n", not_a);
    printf("Bitwise NOT (~b): %d\n", not_b);

}
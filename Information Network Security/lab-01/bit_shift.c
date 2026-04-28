#include <stdio.h>

int main() {
    unsigned int num, left_rot, right_rot, bits;
    printf("Enter an integer: ");
    scanf("%u", &num);
    printf("Enter number of bits to rotate: ");
    scanf("%u", &bits);

    int total_bits = sizeof(num) * 8;

    bits = bits % total_bits;

    left_rot = (num << bits) | (num >> (total_bits - bits));
    right_rot = (num >> bits) | (num << (total_bits - bits));

    printf("Left Circular Rotation by %u bits: %u\n", bits, left_rot);
    printf("Right Circular Rotation by %u bits: %u\n", bits, right_rot);
}

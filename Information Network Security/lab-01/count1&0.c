#include <stdio.h>
int main() {
    int n, ones = 0, zeros = 0, temp;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n; 
    printf("Binary: ");

    while (temp > 0)
    {
        int bit = temp % 2;
        printf("%d", bit);   
        if (bit == 0)
            zeros++;
        else
            ones++;
        temp = temp / 2;
    }

    printf("\n1s = %d, 0s = %d", zeros, ones);
}
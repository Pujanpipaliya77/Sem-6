#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int power(int base, int exp, int mod) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

int main() {
    int p, q, e;
    int n, phi, d = 0;
    int M, C, decrypted;

    printf("Enter prime number p: ");
    scanf("%d", &p);

    printf("Enter prime number q: ");
    scanf("%d", &q);

    printf("Enter public key e: ");
    scanf("%d", &e);

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("\nValue of n = %d\n", n);
    printf("Value of phi(n) = %d\n", phi);

    if (gcd(e, phi) != 1) {
        printf("Invalid public key e. GCD(e, phi) must be 1.\n");
        return 0;
    }

    for (int i = 1; i < phi; i++) {
        if ((e * i) % phi == 1) {
            d = i;
            break;
        }
    }

    printf("Private Key (d) = %d\n", d);

    printf("\nEnter message(M): ");
    scanf("%d", &M);

    C = power(M, e, n);
    printf("Encrypted Message = %d\n", C);

    decrypted = power(C, d, n);
    printf("Decrypted Message = %d\n", decrypted);
    
    return 0;
}
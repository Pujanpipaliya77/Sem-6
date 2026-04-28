#include <stdio.h>

long mod_exp(long base, long exp, long mod) {
    long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int main() {
    long p, g;        
    long a, b;        
    long A, B;        
    long keyA, keyB;  

    printf("Enter prime number p: ");
    scanf("%ld", &p);

    printf("Enter primitive root g: ");
    scanf("%ld", &g);

    printf("Enter private key of User A: ");
    scanf("%ld", &a);

    printf("Enter private key of User B: ");
    scanf("%ld", &b);

    A = mod_exp(g, a, p);
    B = mod_exp(g, b, p);

    printf("\nPublic Values:\n");
    printf("Public key of User A (A) = %ld\n", A);
    printf("Public key of User B (B) = %ld\n", B);

    keyA = mod_exp(B, a, p);
    keyB = mod_exp(A, b, p);

    printf("\nShared Secret Keys:\n");
    printf("Key calculated by User A = %ld\n", keyA);
    printf("Key calculated by User B = %ld\n", keyB);

    return 0;
}

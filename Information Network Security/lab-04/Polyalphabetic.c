#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char plaintext[500], key[500], ciphertext[500];
    int i, j = 0;
    printf("Enter plaintext: ");
    scanf(" %[^\n]", plaintext);   
    printf("Enter key: ");
    scanf(" %[^\n]", key);
    int keyLen = strlen(key);
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            int p = toupper(plaintext[i]) - 'A';
            int k = toupper(key[j % keyLen]) - 'A';

            ciphertext[i] = (p + k) % 26 + 'A';
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
    printf("Ciphertext (UPPERCASE): %s\n", ciphertext);
}
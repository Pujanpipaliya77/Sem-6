// hill_cipher 2x2 matrix multiplication

#include <stdio.h>
#include <string.h>

int main()
{
    int key[2][2];
    int p[2], c[2];
    char plaintext[100];

    printf("Enter 2x2 key matrix:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &key[i][j]);
        }
    }

    printf("Enter plaintext (Captial letters): ");
    scanf("%s", plaintext);

    int len = strlen(plaintext);
    printf("Ciphertext: ");
    
    for (int i = 0; i < len; i += 2)
    {
        p[0] = plaintext[i] - 'A';
        p[1] = plaintext[i + 1] - 'A';
        c[0] = (key[0][0] * p[0] + key[0][1] * p[1]) % 26;
        c[1] = (key[1][0] * p[0] + key[1][1] * p[1]) % 26;
        printf("%c%c", c[0] + 'A', c[1] + 'A');
    }
}

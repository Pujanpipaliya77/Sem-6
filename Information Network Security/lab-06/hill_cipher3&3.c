// hill_cipher 3x3 matrix multiplication

#include <stdio.h>
#include <string.h>

int main()
{
    int key[3][3];
    int p[3], c[3];
    char plaintext[100];

    printf("Enter 3x3 key matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &key[i][j]);
        }
    }

    printf("Enter plaintext (Capital letters) : ");
    scanf("%s", plaintext);

    int len = strlen(plaintext);

    printf("Ciphertext: ");

    for (int i = 0; i < len; i += 3)
    {

        p[0] = plaintext[i] - 'A';
        p[1] = plaintext[i + 1] - 'A';
        p[2] = plaintext[i + 2] - 'A';

        for (int j = 0; j < 3; j++)
        {
            c[j] = (key[j][0]*p[0] + key[j][1]*p[1] + key[j][2]*p[2]) % 26;
        }

        printf("%c%c%c", c[0] + 'A', c[1] + 'A', c[2] + 'A');
    }
}

#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char plaintext[100], key[100];
    char cipherAlpha[26];
    int used[26] = {0};
    int i, j = 0;
    printf("Enter plaintext: ");
    scanf(" %[^\n]", plaintext);
    printf("Enter key: ");
    scanf(" %s", key);
    for (i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);
        if (isalpha(ch) && !used[ch - 'A'])
        {
            cipherAlpha[j++] = ch;
            used[ch - 'A'] = 1;
        }
    }
    for (i = 0; i < 26; i++)
    {
        if (!used[i])
        {
            cipherAlpha[j++] = 'A' + i;
        }
    }
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            plaintext[i] = cipherAlpha[toupper(plaintext[i]) - 'A'];
        }
    }
    printf("\nCiphertext: %s", plaintext);
}
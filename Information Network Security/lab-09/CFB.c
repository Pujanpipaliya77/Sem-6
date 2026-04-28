#include <stdio.h>
#include <string.h>

#define B 8  

void encrypt_block(char *block, char *key)
{
    int i;
    for (i = 0; i < B; i++)
        block[i] = block[i] ^ key[i];
}

void decrypt_block(char *block, char *key)
{
    int i;
    for (i = 0; i < B; i++)
        block[i] = block[i] ^ key[i];
}

int pad_data(char *data)
{
    int len = strlen(data);
    while (len % B != 0)
    {
        data[len] = ' ';
        len++;
    }
    data[len] = '\0';
    return len;
}

void print_byte_binary(char b)
{
    for (int i = 7; i >= 0; i--)
        printf("%d", (b >> i) & 1);
    printf(" "); 
}

int main()
{
    char data[100], key[100], iv[B] = "initvect";
    char original[100], prev[B], temp[B];

    printf("Enter plaintext: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';

    printf("Enter 8-byte key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    strcpy(original, data);
    int len = pad_data(data);

    printf("\nOriginal Data: %s\n", data);

    memcpy(prev, iv, B);

    for (int i = 0; i < len; i += B)
    {
        memcpy(temp, prev, B);
        encrypt_block(temp, key);

        for (int j = 0; j < B; j++)
        {
            data[i + j] ^= temp[j];
            prev[j] = data[i + j];
        }
    }

    printf("Encrypted (Binary): ");
    for (int i = 0; i < len; i++)
        print_byte_binary(data[i]);
    printf("\n");

    memcpy(prev, iv, B);
    for (int i = 0; i < len; i += B)
    {
        memcpy(temp, prev, B);
        encrypt_block(temp, key);

        for (int j = 0; j < B; j++)
        {
            char c = data[i + j];
            data[i + j] ^= temp[j];
            prev[j] = c;
        }
    }

    printf("Decrypted Data: %s\n", data);
    return 0;
}

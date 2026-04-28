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
    char data[100], key[B + 1];
    int len, i;

    printf("Enter plaintext: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';

    printf("Enter 8-byte key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 

    len = pad_data(data);

    printf("\nOriginal Data: %s\n", data);

    for (i = 0; i < len; i += B)
        encrypt_block(&data[i], key);

    printf("Cipher (Binary): ");
    for (i = 0; i < len; i++)
        print_byte_binary(data[i]);
    printf("\n");

    for (i = 0; i < len; i += B)
        decrypt_block(&data[i], key);

    printf("Decrypted Data: %s\n", data);

}
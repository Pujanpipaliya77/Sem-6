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
    char data[100], key[100];
    char ctr[B] = "counter1";   // initial counter
    char ctr_copy[B];           // to restore counter for decryption
    char temp[B];

    printf("Enter plaintext: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';

    printf("Enter 8-byte key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    int len = pad_data(data);  // call your padding function

    printf("\nOriginal Data: %s\n", data);

    memcpy(ctr_copy, ctr, B);  // save counter

    // ----- Encryption using your encrypt_block -----
    for (int i = 0; i < len; i += B)
    {
        memcpy(temp, ctr, B);
        encrypt_block(temp, key);   // call your function

        for (int j = 0; j < B; j++)
            data[i + j] ^= temp[j];

        ctr[B - 1]++;   // increment counter
    }

    // Print encrypted binary using your function
    printf("Encrypted (Binary): ");
    for (int i = 0; i < len; i++)
        print_byte_binary(data[i]);  // call your function
    printf("\n");

    memcpy(ctr, ctr_copy, B);  // restore counter

    for (int i = 0; i < len; i += B)
    {
        memcpy(temp, ctr, B);
        encrypt_block(temp, key);   // call your function again

        for (int j = 0; j < B; j++)
            data[i + j] ^= temp[j];

        ctr[B - 1]++;
    }

    printf("Decrypted Data: %s\n", data);

    return 0;
}

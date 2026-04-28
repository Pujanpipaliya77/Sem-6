#include <stdio.h>
#include <string.h>

int main()
{
    char data[100], received[100];
    int hash1 = 0, hash2 = 0;
    int i;

    printf("Enter data to send: ");
    scanf("%s", data);

    for(i = 0; i < strlen(data); i++)
    {
        hash1 = hash1 + data[i];
    }

    hash1 = hash1 % 100;

    printf("Hash sent with data: %d\n", hash1);

    printf("Enter received data: ");
    scanf("%s", received);

    for(i = 0; i < strlen(received); i++)
    {
        hash2 = hash2 + received[i];
    }

    hash2 = hash2 % 100;

    if(hash1 == hash2){
        printf("Data is NOT corrupted\n");
    }
    else{
        printf("Data is corrupted\n");
    }
}
#include <stdio.h>

int main()
{
    int data[10], n;
    int sum = 0, checksum;

    printf("Enter number of data elements: ");
    scanf("%d", &n);

    printf("Enter the data elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
        sum = sum + data[i];
    }

    checksum = sum % 256;   

    printf("Checksum value: %d\n", checksum);
}
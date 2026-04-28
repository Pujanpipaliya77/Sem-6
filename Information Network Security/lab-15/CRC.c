#include <stdio.h>
#include <string.h>

int main()
{
    char data[20], generator[20];
    char temp[20], remainder[20];
    int data_len, gen_len, i, j;

    printf("Enter data: ");
    scanf("%s", data);

    printf("Enter generator: ");
    scanf("%s", generator);

    data_len = strlen(data);
    gen_len = strlen(generator);

    strcpy(temp, data);

    for(i = data_len; i < data_len + gen_len - 1; i++)
        temp[i] = '0';

    temp[data_len + gen_len - 1] = '\0';

    strcpy(remainder, temp);

    for(i = 0; i < data_len; i++)
    {
        if(remainder[i] == '1')
        {
            for(j = 0; j < gen_len; j++)
            {
                remainder[i+j] = ((remainder[i+j] == generator[j]) ? '0' : '1');
            }
        }
    }

    printf("CRC: ");
    for(i = data_len; i < data_len + gen_len - 1; i++)
        printf("%c", remainder[i]);

    printf("\n");
}
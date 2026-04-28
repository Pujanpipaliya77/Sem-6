#include <stdio.h>

int main()
{
    char text[100];
    int i = 0, key;

    printf("Enter plain text : ");
    scanf("%[^\n]", text);

    printf("Enter key in number : ");
    scanf("%d", &key);

    while (text[i] != '\0')
    {

        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = text[i] + key;
            if (text[i] > 'Z')
            {
                text[i] = text[i] - 26;
            }
        }

        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = text[i] + key;
            if (text[i] > 'z')
            {
                text[i] = text[i] - 26;
            }
        }

        else
        {
            text[i] = text[i];
        }

        i++;
    }
    printf("Cipher text : %s", text);
}
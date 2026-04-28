#include <stdio.h>
#include <ctype.h>
void main()
{
    char pt[100], key[100], pairedPt[100], matrix[5][5];
    int usedkey[26] = {0};
    int i, j, x = 0, len = 0;
    int r1, r2, c1, c2;
    printf("Enter plaintext: ");
    scanf(" %[^\n]", pt);
    printf("Enter key: ");
    scanf(" %[^\n]", key);
    for (i = 0; pt[i]; i++)
    {
        if (isalpha(pt[i]))
        {
            char ch = toupper(pt[i]);
            pairedPt[len++] = (ch == 'J') ? 'I' : ch;
        }
    }
    pairedPt[len] = '\0';
    usedkey['J' - 'A'] = 1;
    for (i = 0; key[i]; i++)
    {
        char ch = toupper(key[i]);
        if (!isalpha(ch))
            continue;
        if (ch == 'J')
            ch = 'I';
        if (!usedkey[ch - 'A'])
        {
            matrix[x / 5][x % 5] = ch;
            usedkey[ch - 'A'] = 1;
            x++;
        }
    }
    for (i = 0; i < 26; i++)
    {
        if (!usedkey[i])
        {
            matrix[x / 5][x % 5] = 'A' + i;
            x++;
        }
    }

    printf("Ciphertext: ");
    for (i = 0; i < len; i++)
    {
        char a = pairedPt[i];
        char b;

        if (i + 1 < len && pairedPt[i] == pairedPt[i + 1])
        {
            b = 'X';
        }
        else
        {
            b = (i + 1 < len) ? pairedPt[++i] : 'X';
        }
        for (j = 0; j < 25; j++)
        {
            if (matrix[j / 5][j % 5] == a)
                r1 = j / 5, c1 = j % 5;
            if (matrix[j / 5][j % 5] == b)
                r2 = j / 5, c2 = j % 5;
        }
        if (r1 == r2)
            printf("%c%c", matrix[r1][(c1 + 1) % 5], matrix[r2][(c2 + 1) % 5]);
        else if (c1 == c2)
            printf("%c%c", matrix[(r1 + 1) % 5][c1], matrix[(r2 + 1) % 5][c2]);
        else
            printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
    }
}

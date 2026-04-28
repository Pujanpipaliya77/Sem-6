#include <stdio.h>

int main()
{
    int start, end, i, j, flag;
    printf("Enter start and end: ");
    scanf("%d %d", &start, &end);

    printf("Prime numbers between %d and %d are: ", start, end);

    for (i = start; i <= end; i++)
    {
        if (i < 2)
        {
            continue;
        }

        flag = 1;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d ", i);
        }
    }
}

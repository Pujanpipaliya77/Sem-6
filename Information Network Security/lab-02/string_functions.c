#include <stdio.h>
#include <string.h>

int main() {
    char str1[200], str2[200];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    printf("Length of first string: %zu\n", strlen(str1));
    printf("Length of second string: %zu\n", strlen(str2));

    printf("After strcat: %s%s", str1, str2); 

    int result = strcmp(str1, str2);

    if (result == 0)
        printf("Strings are equal.\n");
    else if (result > 0)
        printf("First string is greater.\n");
    else
        printf("Second string is greater .\n");
}

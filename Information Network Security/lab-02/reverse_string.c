#include <stdio.h>
#include <string.h>

int main() {
    char str[100], *p, *q, temp;

    printf("Enter a string: ");
    scanf("%s", str); 

    p = str;
    q = str + strlen(str) - 1;

    while (p < q) {
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
    
    printf("Reversed string is: %s\n", str);
}

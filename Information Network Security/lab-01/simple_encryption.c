
#include <stdio.h>

void main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    char encrypted[100];

    int n;
    printf("Enter a constant value : ");
    scanf("%d", &n);

    for(int i = 0; str[i] != '\0'; i++){
        encrypted[i] = (str[i] & n) ^ n; 
    }
    
    printf("Encrypted string: %s\n", encrypted);    
}


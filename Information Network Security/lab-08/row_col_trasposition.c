#include <stdio.h>
#include <string.h>

int main() {
    char plain[200], text[200];
    char keystr[20];
    int key[20];
    int i, j, k = 0, cols, rows, len;

    printf("Enter key: ");
    scanf("%s", keystr);

    cols = strlen(keystr);

    for (i = 0; i < cols; i++){
        key[i] = keystr[i] - '0';
    }

    printf("Enter plaintext: ");
    getchar();
    gets(plain);

    for (i = 0; plain[i] != '\0'; i++) {
        if (plain[i] != ' ')
            text[k++] = plain[i];
    }

    text[k] = '\0';

    len = strlen(text);
    rows = len / cols;
    if (len % cols != 0){
        rows++;
    }
    char mat[rows][cols];

    k = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (k < len){
                mat[i][j] = text[k++];
            }
            else{
                mat[i][j] = 'x';
            }
        }
    }

    printf("\nKey: %s", keystr);
    printf("\nPlaintext: %s", plain);
    printf("\nCiphertext: ");

    int count = 0;

    for (i = 1; i <= cols; i++) {
        for (j = 0; j < cols; j++) {
            if (key[j] == i) {
                for (k = 0; k < rows; k++) {
                    printf("%c", mat[k][j]);
                    count++;
                    if (count % cols == 0)
                        printf(" ");
                }
            }
        }
    }
}
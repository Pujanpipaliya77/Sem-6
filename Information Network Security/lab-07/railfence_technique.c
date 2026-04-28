#include <stdio.h>
#include <string.h>

int main() {
    char text[100], rail[10][100];
    int i, j, row = 0, dir = 1;
    int len, key;

    printf("Enter plaintext: ");
    scanf("%[^\n]", text);

    printf("Enter key:  ");
    scanf("%d", &key);

    len = strlen(text);

    for (i = 0; i < key; i++){
        for (j = 0; j < len; j++){
            rail[i][j] = '\n';
        }
    }

    for (i = 0; i < len; i++) {
        rail[row][i] = text[i];

        if (row == 0){
            dir = 1;
        }
        else if (row == key - 1){
            dir = -1;
        }

        row = row + dir;
    }

    printf("Ciphertext: ");
    for (i = 0; i < key; i++){
        for (j = 0; j < len; j++){
            if (rail[i][j] != '\n'){
                printf("%c", rail[i][j]);
            }
        }
    }
}

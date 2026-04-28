#include <stdio.h>
int main() {
    FILE *fp;
    char text[100];
    
    fp = fopen("example.txt", "w");
    printf("Enter text: ");
    scanf("%[^\n]", text);     
    
    fprintf(fp, "%s", text);   
    
    fclose(fp);

    fp = fopen("example.txt", "r");
    fscanf(fp, "%[^\n]", text);
    printf("File says: %s", text);

    fclose(fp);
}
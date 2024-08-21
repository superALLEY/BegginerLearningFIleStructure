#include <stdio.h>

int main() {


    int lineCount = 0;
    char ch;
    int i=0;
    int j=0;
   FILE *file = fopen("f1.txt", "r");

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
        if (ch==' ') {
        j++;
        }
        i++;
    }



    rewind(file);
    fclose(file);

    printf("Nombre de lignes dans le fichier : %d\n", lineCount);
    printf("Nombre de caracteres dans le fichier : %d\n", i-lineCount+1);
     printf("Nombre de mots dans le fichier : %d\n", j);


    return 0;
}

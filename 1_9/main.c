#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main() {
    char file11[] = "input.txt";
    char file22[] = "output.txt";
    char line[256];

    FILE *file1 = fopen(file11, "r");
    FILE *file2 = fopen(file22, "w");
char lines[1000][1000];
    int co = 0;

    while (fgets(line, sizeof(line), file1)) {
        bool x = false;

        for (int i = 0; i < co; i++) {
            if (strcmp(line, lines[i]) == 0) {
                x= true;
                break;
            }
        }

        if (!x) {

            fputs(line, file2);


            if (co < 1000) {
                strcpy(lines[co], line);
                co++;
    }
        }
    }
    fclose(file1);
    fclose(file2);



    return 0;
}

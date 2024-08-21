#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_valid_email_char(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '.' || c == '@' || c == '_' || c == '-';
}

bool is_valid_email(const char *str) {
    int at_count = 0;
    int dot_count = 0;

    for (int i = 0; str[i]; i++) {
        if (!is_valid_email_char(str[i]))
            return false;
        if (str[i] == '@') {
            at_count++;
            if (at_count > 1)
                return false;
        }
        if (str[i] == '.') {
            dot_count++;
            if (dot_count > 1)
                return false;
        }
    }
    return at_count == 1 && dot_count == 1;
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFilename[] = "input.txt";
    char outputFilename[] = "output.txt";

    inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return 1;
    }

    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sortie");
        fclose(inputFile);
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), inputFile)) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            int j = i;
            while (is_valid_email_char(line[j]))
                j++;
            if (j > i) {
                char candidate[j - i + 1];
                strncpy(candidate, line + i, j - i);
                candidate[j - i] = '\0';
                if (is_valid_email(candidate)) {
                    fprintf(outputFile, "%s\n", candidate);
                }
                i = j;
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

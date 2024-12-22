#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *uzbekFile, *englishFile, *outputFile;
    char uzbekWord[256], englishWord[256];

  
    uzbekFile = fopen("uzbek.txt", "r");
    if (uzbekFile == NULL) {
        return 1;
    }

    englishFile = fopen("english.txt", "r");
    if (englishFile == NULL) {
        fclose(uzbekFile);
        return 1;
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        fclose(uzbekFile);
        fclose(englishFile);
        return 1;
    }
    while (fgets(uzbekWord, sizeof(uzbekWord), uzbekFile) != NULL &&
           fgets(englishWord, sizeof(englishWord), englishFile) != NULL) {
        uzbekWord[strcspn(uzbekWord, "\n")] = '\0';
        englishWord[strcspn(englishWord, "\n")] = '\0';

        fprintf(outputFile, "%s - %s\n", englishWord, uzbekWord);
    }

    fclose(uzbekFile);
    fclose(englishFile);
    fclose(outputFile);

    return 0;
}
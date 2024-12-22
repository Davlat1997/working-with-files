#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char word[100], longest[100] = "", shortest[100] = "";
    int firstWord = 1;

    
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%s", word) != EOF) {
        if (firstWord) {
            strcpy(longest, word);
            strcpy(shortest, word);
            firstWord = 0;
        } else {
            if (strlen(word) > strlen(longest)) {
                strcpy(longest, word);
            }
            if (strlen(word) < strlen(shortest)) {
                strcpy(shortest, word);
            }
        }
    }
    fprintf(outputFile, "Eng uzun so'z: %s\n", longest);
    fprintf(outputFile, "Eng qisqa so'z: %s\n", shortest);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
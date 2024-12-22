#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char line[256];
    char searchText[256];
    int found = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("input.txt faylini ochib bo'lmadi.\n");
        return 1;
    }

    printf("Qaysi matnli qatorni qidiryapsiz? ");
    fgets(searchText, sizeof(searchText), stdin);
    searchText[strcspn(searchText, "\n")] = '\0'; 

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("output.txt faylini yaratib bo'lmadi.\n");
        fclose(inputFile);
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)) {
        if (strstr(line, searchText) != NULL) { 
            fputs(line, outputFile);
            found = 1;
            break;
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    if (found) {
        printf("Matn topildi va output.txt fayliga yozildi.\n");
    } else {
        printf("Matn topilmadi.\n");
    }

    return 0;
}
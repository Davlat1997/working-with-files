#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    int num;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        return 1;
    }
   
    fprintf(outputFile, "Juft sonlar: ");
    while (fscanf(inputFile, "%d", &num) != EOF) {
        if (num % 2 == 0) {
            fprintf(outputFile, "%d ", num);
        }
    }

    rewind(inputFile);
    fprintf(outputFile, "\nToq sonlar: ");
    while (fscanf(inputFile, "%d", &num) != EOF) {
        if (num % 2 != 0) {
            fprintf(outputFile, "%d ", num);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
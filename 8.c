#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    int asciiValue;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        return 1;
    }

    
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%d", &asciiValue) != EOF) {
        fputc(asciiValue, outputFile); 
    }

    fclose(inputFile);
    fclose(outputFile);

   
    return 0;
}
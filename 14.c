#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    int num1, num2, result;
    char operator;
    
    inputFile = fopen("Input.txt", "r");
    if (inputFile == NULL) {
        return 1;
    }

    outputFile = fopen("Output.txt", "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%d %c %d", &num1, &operator, &num2) == 3) {
        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    fprintf(outputFile, " 0 ga bo'lish.\n");
                    continue;
                }
                break;
            default:
                fprintf(outputFile, " amal: %c\n", operator);
                continue;
        }

        fprintf(outputFile, "%d %c %d = %d\n", num1, operator, num2, result);
    }

    fclose(inputFile);
    fclose(outputFile);


    return 0;
}
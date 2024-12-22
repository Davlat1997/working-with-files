#include <stdio.h>

int main() {
    FILE *outputFile;
    int numbers[5], sum = 0;
    int i;

    printf("5 ta sonni kiriting: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("new.txt faylini yaratib bo'lmadi.\n");
        return 1;
    }

   
    for (i = 0; i < 5; i++) {
        fprintf(outputFile, "%d", numbers[i]);
        if (i < 4) {
            fprintf(outputFile, "+");
        }
    }
    fprintf(outputFile, "=%d\n", sum);

    fclose(outputFile);

    printf("Sonlarning yig'indisi output.txt fayliga yozildi.\n");
    return 0;
}
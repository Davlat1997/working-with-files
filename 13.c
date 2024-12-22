#include <stdio.h>

int main() {
    FILE *outputFile;
    int N, sum = 0;
    
    printf("sonni kiriting: ");
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        sum += i;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        return 1;
    }

    for (int i = 1; i <= N; i++) {
        fprintf(outputFile, "%d", i);
        if (i < N) {
            fprintf(outputFile, "+");
        }
    }
    fprintf(outputFile, "=%d\n", sum);

    fclose(outputFile);


    return 0;
}
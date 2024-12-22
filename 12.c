#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *utganFile, *utmaganFile;
    char name[50]; 
    int ball;    
    int M = 60;    

  
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        return 1;
    }


    utganFile = fopen("utgan.txt", "w");
    utmaganFile = fopen("utmagan.txt", "w");

    if (utganFile == NULL || utmaganFile == NULL) {
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%s %d", name, &ball) == 2) {
        if (ball >= M) {
            fprintf(utganFile, "%s %d\n", name, ball);
        } else {
            fprintf(utmaganFile, "%s %d\n", name, ball);
        }
    }

    fclose(inputFile);
    fclose(utganFile);
    fclose(utmaganFile);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *infile, *outfile;
    int numbers[10], birinchi, oxirgi;
    int i;

    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        return 1;
    }

    for (i = 0; i < 10; i++) {
        if (fscanf(infile, "%d", &numbers[i]) != 1) {
            fclose(infile);
            return 1;
        }
    }
    fclose(infile);

    birinchi = numbers[0];
    oxirgi = numbers[9];

    outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        return 1;
    }
    fprintf(outfile, "Dastlabki son: %d\n", birinchi);
    fprintf(outfile, "Oxirgi son: %d\n", oxirgi);
    fclose(outfile);

    return 0;
}
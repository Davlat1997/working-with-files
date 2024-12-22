#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *infile, *outfile;
    char ch;
    int plus = 0, minus = 0, kupaytma = 0, buluv = 0, qavs = 0, qavs2 = 0;

    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        return 1;
    }

    while ((ch = fgetc(infile)) != EOF) {
        if (ch == '+') plus++;
        else if (ch == '-') minus++;
        else if (ch == '*') kupaytma++;
        else if (ch == '/') buluv++;
        else if (ch == '(') qavs++;
        else if (ch == ')') qavs2++;
    }
    fclose(infile);
    outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        return 1;
    }
    fprintf(outfile, " (+): %d\n", plus);
    fprintf(outfile, " (-): %d\n", minus);
    fprintf(outfile, " (*): %d\n", kupaytma);
    fprintf(outfile, " (/): %d\n", buluv);
    fprintf(outfile, " ((): %d\n", qavs);
    fprintf(outfile, " ()): %d\n", qavs2);
    fclose(outfile);

    return 0;
}
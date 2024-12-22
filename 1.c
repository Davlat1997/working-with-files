#include <stdio.h>

int main() {
    FILE *f, *output;
    int num, sum = 0, count = 0;
    float urtacha;

    f = fopen("input.txt", "r");
    if (f == NULL) {
        return 1;
    }

    output = fopen("output.txt", "w");
    if (output == NULL) {
        fclose(f);
        return 1;
    }

    while (fscanf(f, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count > 0) {
        urtacha = (float)sum / count;
        fprintf(output, "Sonlarning o'rta arifmetigi: %.2f\n", urtacha);
    } 
    
    fclose(f);
    fclose(output);

    return 0;
}
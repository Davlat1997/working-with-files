#include <stdio.h>

int main() {
    FILE *f;
    int num, sum = 0, count = 0;
    float urtacha;

    f = fopen("output.txt", "r");
    if (f == NULL) {
        return 1;
    }

    while (fscanf(f, "%d", &num) == 1) {
        sum += num;
        count++;
    }

   
    if (count > 0) {
        urtacha = (float)sum / count;
        printf("Sonlarning o'rta arifmetigi: %.2f\n", urtacha);
    } else {
        printf("Faylda sonlar topilmadi.\n");
    }
    fclose(f);
    
    return 0;
}
    

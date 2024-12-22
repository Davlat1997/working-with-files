#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char ch;
    int suz = 1;
 
    file = fopen("output.txt", "r+");
    if (file == NULL) {
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        if (suz && isalpha(ch)) {
         
            fseek(file, -1, SEEK_CUR); 
            fputc(toupper(ch), file);
            fseek(file, 0, SEEK_CUR);
            suz = 0;   
        } else if (isspace(ch) || ispunct(ch)) {
            suz = 1;
        }
    }
    fclose(file);

    return 0;
}
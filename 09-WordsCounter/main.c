#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    FILE *input;
    char str[256];
    int words = 0,lines = 0, characters = 0, i, in_word = 0;

    input = fopen("Input.txt", "r");
    if (input == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    while (fgets(str, sizeof(str), input) != NULL){
        lines += 1;
        characters += strlen(str);
        for (int i = 0; str[i] != '\0'; i++) {
            if (isspace(str[i])) {
                if (in_word) {
                    in_word = 0;
                    words++;
                }
            } else {
                in_word = 1;
            }
        }
        if (in_word) {
            words++;
            in_word = 0;
        }
    }
    printf("The number of words in the file is:      %d\n", words);
    printf("The number of lines in the file is:      %d\n", lines);
    printf("The number of Characters in the file is: %d\n", characters);
    fclose(input);
    return 0;
}
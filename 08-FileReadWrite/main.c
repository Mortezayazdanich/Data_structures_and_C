#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void){
    FILE *output;
    char str[100];

    strcpy(str, "Hello World\nThis is a test file\nAnother line \n");
    output = fopen("Output.txt", "w+");
    if (output == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fprintf(output, "%s", str);
    rewind(output);
    while (fgets(str, 100, output) != NULL){
        printf("%s", str);
    }
    fclose(output);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int isvowel(char c);

#define SIZE  50

int main(void){
  char str[SIZE];
  bool pal;
  int len, vowels = 0, numerics = 0, consonants = 0, spaces = 0;
  
  printf("Enter a String(50 Chars):");
  fgets(str, SIZE, stdin);
  len = strlen(str);
  for(int i = 0; i < len; i++){
    if (isdigit(str[i])) {
      numerics += 1;
    } else if (isvowel(str[i])) {
      vowels += 1;
    } else if (str[i] == ' ') {
      spaces += 1;
    } else if (!isvowel(str[i])) {
      consonants += 1;
    }
  }
  
  printf("The Following are the counts for the string: %s\n", str);
  printf("    |--> Vowels Count:     %d\n", vowels);
  printf("    |--> Digits Count:     %d\n", numerics);
  printf("    |--> Consonants Count: %d\n", consonants);
  printf("    |--> Spaces Count:     %d\n", spaces);
  
  return 0;
}

int isvowel(char c) {
    switch(tolower(c)){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
    }
}

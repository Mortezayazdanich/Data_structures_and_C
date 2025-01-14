#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE  20

int main(void){
  char str[SIZE];
  bool pal = true;
  int len;
  
  printf("Enter a String(20 Chars):");
  scanf("%s",str);
  len = strlen(str);
  
  for(int i = 0; i < (len/2); i++){
    if(str[i] != str[len-i-1]){
      pal = false;
    }  
  }
  
  if(pal == true)
    printf("The String is Palindrome!");
  else
    printf("The String is not Palindrome");
  
  return 0;
}

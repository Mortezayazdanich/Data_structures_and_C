#include <stdlib.h>
#include <stdio.h>

#define STR_SIZE  12

int main(void){
  char str[] = "Hello World!",tmp_c;
  int k = STR_SIZE-1;
  for(int i = 0; i < STR_SIZE; i++){
    for(int j = 0; j < k; j++){
        tmp_c = str[j+1];
        str[j+1] = str[j];
        str[j] = tmp_c;
    }
    k -= 1;
  }

  for(int y = 0; y < STR_SIZE; y++){
    printf("%c", str[y]);
  }
  return 0;
}

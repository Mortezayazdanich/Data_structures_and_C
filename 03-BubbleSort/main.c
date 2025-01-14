#include <stdlib.h>
#include <stdio.h>

#define SIZE  20

int main(void){
  int list[SIZE] = {73, 11, 5, 96, 56, 25, 22, 91, 84, 83, 79, 93, 37, 49, 88, 12, 18, 41, 3, 92}; //of size 20
  int k = SIZE-1, tmp;
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < k; j++){
      if(list[j] > list[j+1]){
        tmp = list[j+1];
        list[j+1] = list[j];
        list[j] = tmp;
      }
    }
    k -= 1;
  }

  for(int y = 0; y < SIZE; y++){
    printf("%d, ", list[y]);
  }
  return 0;
}

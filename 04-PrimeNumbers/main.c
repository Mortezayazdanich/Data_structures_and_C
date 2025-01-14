#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define SIZE  20

int main(void){
  int list[SIZE] = {73, 11, 5, 96, 56, 25, 22, 91, 84, 83, 79, 93, 37, 49, 88, 12, 18, 41, 3, 92}; //of size 20
  int tmp;
  bool check;

  for(int i = 0; i < SIZE; i++){
    check = true;
    for(int j = 2; j < sqrt(list[i]) && check == true; j++){
      if( list[i] % j == 0){
        check = false;
        break;
      }
    }
    if(check==true){
      printf("The number %d is Prime. \n", list[i]);
    } else{
      printf("The number %d is NOT Prime. \n", list[i]);
    }
  }  
  return 0;
}

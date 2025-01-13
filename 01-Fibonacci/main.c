#include <stdlib.h>
#include <stdio.h>

int main(void){
  int n;
  int ith_element = 0, prev_element = 1;
  printf("Size of the Fibonacci sequence?: ");
  scanf("%d", n);
  if(n>0){
    printf("%d, ",prev_element);
    for(int i = 1; i < n ; i++){
      ith_element += prev_element;
      printf("%d, ", ith_element);
    }
  }
  printf("\n");
  return 0;
}

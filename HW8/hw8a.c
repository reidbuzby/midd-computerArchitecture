/*
This is starter code for the first part of assignment 8.

Your task is to reimplement buildArray(). The challenge is that you are only allowed a single call to malloc and no calls to calloc.
*/

#include <stdio.h>
#include <stdlib.h>


#define ROWS 5
#define COLS 4


int ** buildArray(int rows, int columns) {
  int ** array;
  char* temp;
  array = (int**)malloc((columns * (rows * sizeof(int))) + (sizeof(int*) * rows));
  temp = (char*)array + (sizeof(int*) * rows);
  for(int i = 0; i < rows; i++) {
    array[i] = (int*)(temp + ((rows * sizeof(int)) * i));
  }
  return array;
}


int main(int argc, char * argv[]){
  int ** a = buildArray(ROWS, COLS);
  for (int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS; j++){
      a[i][j] = i* COLS+j;

    }
  }


  printf("A: \n");
  for (int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS; j++){

      printf("a[%d][%d] = %d [%p]\n", i, j, a[i][j], &a[i][j]);

    }
    printf("\n");
  }

  return 0;
}

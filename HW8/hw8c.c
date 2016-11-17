/*
Starter code for Assignment 8

I have provided you with the basic structure of a program that reads in inputs and does some basic
error handling. Your task is to implement the linked list functionality of the tool. You will need to
define an appropriate type for storing the linked list. You then need to write three functions: one that
adds values to the list, one that removes values from the list and one that prints out the list on a single
line.

The addValue function should take in a list and the number to add and return the list. The number should be added on the _end_ of the list.

The removeValue function should take in a list and a value to remove and return the resulting list. If the
value cannot be found in the list, the function should print a message to that effect to the console (but
still return the list).

The print function should take a list to be printed and return nothing.

*/




#include <stdio.h>
#include <stdlib.h>

#define USAGE "Commands are a single character followed optionally by a number. The valid commands are:\n\t- a <num> (add a number to the list)\n\t- p (print the list)\n\t- r <num> (remove value <num> from the list if present)\n\t- q (quit)"


typedef struct list {
  int length;
  int listLength;
  int value;
} array;

void addValue(array* newArray, int data) {
  if(newArray->listLength > newArray->length) {
    newArray->length = (newArray->length)*2;
    array * temp = realloc(newArray, newArray->length);
    newArray = temp;
    newArray[newArray->listLength].value = data;
    newArray->listLength++;
  }
  else {
    newArray[newArray->listLength].value = data;
    newArray->listLength++;
  }
}

void removeValue(array* newArray, int data) {
  int contains = 0;
  for(int i=0;i<newArray->length;i++) {
    if(newArray[i].value==data) {
      contains = 1;
      for(int j=i;j<newArray->length;j++) {
        newArray[j].value = newArray[j+1].value;
      }
    }

  }
  if(contains==0) {
    printf("List does not contain value");
  }
  else {
    newArray->listLength--;
  }
}


void print(array* newArray) {
  for(int i=0;i<newArray->listLength;i++) {
    printf("%d ", newArray[i].value);
  }
  printf("\n");
}




int main(int argc, char * argv[]){

  int done = 0;
  char input[32];
  char cmd;
  int data;
  int count;


  array * newArray = malloc(5);
  newArray->length=5;
  newArray->listLength=0;

  while (! done){
	printf("Enter a command: ");
	if (fgets(input, 32, stdin) == NULL){
	  printf("%s\n", USAGE);
	}else{
	  count = sscanf(input,"%c %d\n", &cmd, &data);

	  switch (cmd){
	  case 'a':
		if (count != 2){
		  printf("a should be followed by a number to add\n");
		}else{
      addValue(newArray, data);
		}
		break;
	  case 'r':
		if (count != 2){
		  printf("r should be followed by a number to remove\n");
		}else{
      removeValue(newArray, data);
		}
		break;
	  case 'p':
	    print(newArray);
		break;
	  case 'q':
		done = 1;
		break;
	  default:
		printf("%s\n", USAGE);
	  }
	}

  }
  return 0;
}

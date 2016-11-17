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


typedef struct node {
  int data;
  struct node* next;
} linkedList;

void addValue(linkedList * list, int value) {
  linkedList * current = list;
  while(current->next!=NULL) {
    current = current->next;
  }
  current->next = malloc(sizeof(linkedList));
  current->next->data = value;
  current->next->next = NULL;
}

void print(linkedList * list) {
  linkedList * current = list;
  current = current->next;
  while(current!= NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void removeValue(linkedList * list, int value) {
  linkedList * current = list;
  linkedList * previous = list;
  int contains = 0;
  while(current!=NULL) {
    if(current->data == value) {
      contains = 1;
      if(current->next==NULL) {
        previous->next=NULL;
      }
      else {
        previous->next = current->next;
      }
    }
    previous = current;
    current = current->next;
  }
  if(contains == 0) {
    printf("List does not contain value\n");
  }
}



int main(int argc, char * argv[]){

  int done = 0;
  char input[32];
  char cmd;
  int data;
  int count;


  linkedList * list = malloc(sizeof(linkedList));


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
		  addValue(list, data);
		}
		break;
	  case 'r':
		if (count != 2){
		  printf("r should be followed by a number to remove\n");
		}else{
      removeValue(list, data);
		}
		break;
	  case 'p':
      print(list);
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

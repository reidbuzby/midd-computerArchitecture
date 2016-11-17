/*
This is the driver code that you will use for your assembly programs. This
takes input from the users and calls each assembly function in turn, printing
out the results. This is not part of your deliverables, this is just an example
 of how to call these functions.

To compile: gcc -o hw6 hw6_driver.c hw6_asm.s
*/


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "hw6_asm.h"




/**
This function parses a string as an integer.

There are two criteria. First, the entire string must be consumed to be a valid integer, and second, the resulting integer must fit within a long. If neither criteria is met, this exits the program with an error message.

@param input a string containing a number (presumably)

@return a valid long representation of the number
*/
long parseInt(char * input){
	char * endptr;

	long integer = strtol(input, &endptr, 10); // pass address of endptr to the function so it can be set be strtol()

	if (!(endptr != input && *endptr == '\0')){
		// A good parse would move endptr beyond the first character of the input and leave it pointing at the '\0' character at the
		// end of the string (i.e., the whole string has been consumed)
		printf("%s is not a valid integer\n", input);
		exit(-1);
	}else if (errno == ERANGE){
		// Now check if errno got set
		printf("%s is too big\n", input);
		exit(-1);
	}

	// the number is valid, return it
	return integer;
}



int main(int argc, char * argv[]){
  if (argc != 4){
    fprintf(stderr, "Usage: %s <num 1> <num 2> <string>\n", argv[0]);
    return -1;
  }

  int x = parseInt(argv[1]);
  int y = parseInt(argv[2]);
  char* str = argv[3];

  printf("avg: %d\n", avg(x,y));
  printf("maxabs: %d\n", maxabs(x,y));
  printf("lookup: %c\n", lookup(str, x));
  printf("checksum: %x\n", checksum(str));

  return 0;
}

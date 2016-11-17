#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Reid Buzby. Assigment 3. 3/6/16
to compile: gcc hw3_binary.c -o hw3
to run: ./hw3 parameter
*/
int decimal2binary(int num, int step) {//recursive funtion to convert any decimal number to binary
  if(num<2&&num<10) {//base case if the number can be represented as a 1-9 digit
    return num*pow(10, step);
  }
  else {
    int v = floor(num/2);
    int r = num-(v*2);
    return r*pow(10, step) + decimal2binary(v, step+1);
  }
}

int main(int argc, char * argv[]) {
  if(argv[1]==NULL) {//if there are not arguments
    printf("No input\n");
    return 0;
  }
  char * test;
  if(strtol(argv[1], &test, 10)==0) {//check if the input is a number
    printf("%s is not a valid integer\n", argv[1]);
    return 0;
  }
  int num = atoi(argv[1]);
  int count = 0;
	while(pow(2, count)<num) {//figure out how many bits to use
		count++;
	}
	int array[count];
	for(int i=0;i<count;i++) {
		array[i] = 0;
	}
	for(int i=0;i<num+1;i++) {//print out the numbers from 0 to num in binary
		printf("%0*d\n", count, decimal2binary(i, 0));
	}
  return 0;
}

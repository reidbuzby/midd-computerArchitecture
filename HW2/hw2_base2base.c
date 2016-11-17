/*
Reid Buzby. 202 Assignment 2. 2/27/2016
to compile: gcc -o hw2_base2base.c -o hw2_base2base
to run: ./hw2_base2base
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
Function that converts any decimal number to any base taking the parameters num, the number to be converted
and the base to be converted into. Stores the remainder of the num/base in an array
called final. Then resets the num to num/base. Then loops through the final array backwards and checks whether
the number in that element can be represented as a 1-9 digit, or as an A-Z character. The digits and chars are
then printed.
*/
void decimal2base(int num, int base) {
	int count = 0;
	int final[50];
	while(num!=0) {
		final[count] = num % base;
		num = floor(num/base);
		count++;
	}
	for(count--; count>=0;count--) {
		if(final[count]>9) {
			printf("%c", 'A' + final[count]-10);
		}
		else {
			printf("%d", final[count]);
		}
	}
}


int main(int argc, char* argv[]) {

	int base = atoi(argv[2]);
	int newbase = atoi(argv[3]);
	int len = strlen(argv[1]);
	int total = 0;

	for(int i=0;i<len;i++) {//checks if input is either an integer or an uppercase letter based on its ASCII value
		if(!(argv[1][i]>64&&argv[1][i]<91)&&!(argv[1][i]>47&&argv[1][i]<58)) {
			printf("Error: input must only be integers and uppercase letters\n");
			return 0;
		}
	}

	for(int i=0;i<len;i++) {//loops through the inputed integer to check if each digit is an int or a letter (for bases higher than 10)
		int temp;
		if(argv[1][i]>47&&argv[1][i]<58) {
			temp = argv[1][i]-48;
		}
		if(argv[1][i]>64&&argv[1][i]<90) {
			temp = argv[1][i]-55;
		}
		total = total + (temp)*(pow(base, len-i-1));//adds to the total based on the location of the digit and the base
	}
	printf("%d\n", total);

	printf("%s in base %d, is ", argv[1], base);
	decimal2base(total, newbase);//calls the decimal to new base converter
	printf(" in base %d\n", newbase);



	return 0;
	}

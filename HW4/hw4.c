#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Reid Buzby. Assigment 4. 3/ to compile: gcc hw4.c -o hw4
to run: ./hw4
converts every number i in a loop from 0-255 into hex, then prints the 8 bit floating point representation
*/

  void decimal2hex(int num) {//converts decimal numbers to hex and prints the result
    int base = 16;
  	int count = 0;
  	int final[50];
  	while(num!=0) {
  		final[count] = num % base;
  		num = floor(num/base);
  		count++;
  	}
  	for(count--; count>=0;count--) {
  		if(final[count]>9) {
  			printf("%c", 'a' + final[count]-10);
  		}
  		else {
  			printf("%d", final[count]);
  		}
  	}
  }

int main(int argc, char const *argv[]) {
  for(int i=0;i<256;i++) {
    if(i==0) {
      printf("00");
    }
    else if(i<16) {
      printf("0");
      decimal2hex(i);
    }
    else {
      decimal2hex(i);
    }
    printf(": ");
    int sign;
    int exponent10;
    if(i<128) {//if positive number
      sign = 0;
      exponent10 = ((0xF0&i)>>4);
     }
    else {//if negative number
      sign = 1;
      exponent10 = ((0x70&i)>>4);
    }
    int mantissa10 = 0x0F&i;

    if(exponent10==0&&mantissa10==0) {//if zero or -zero
      if(sign==0) {
        printf("0.000000\n");
      }
      if(sign==1) {
        printf("-0.000000\n");
      }
    }
    if(exponent10==0&&!mantissa10==0) {//if denormalized number
      printf("%f\n", pow(-1, sign) * (mantissa10/16.0) * pow(2, -2));
    }
    if(exponent10==7&&mantissa10==0) {//if positive infinity/-infinity
      if(sign==0) {
        printf("&infin\n");
      }
      if(sign==1) {
        printf("-&infin\n");
      }
    }
    if(exponent10==7&&!mantissa10==0) {//if not a number
      printf("NaN\n");
    }
    if(!(exponent10==0||exponent10==7)) {//any number
      printf("%f\n", pow(-1, sign) * (1 + (mantissa10/16.0)) * pow(2, exponent10-3));
    }
  }
  return 0;
}

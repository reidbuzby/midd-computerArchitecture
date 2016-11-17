#include <string.h>
#include <stdio.h>

/* Reid Buzby. 202 Assignment 3 rot13.
To compile: gcc hw3_rot13.c -o hw3
To run: ./hw3 parameters
*/

void rot13(int numlines, char * text[]) {
  for(int i=0; i<numlines;i++) {//loop through each parameter
    for(int j=0;j<strlen(text[i]);j++) {
      if(text[i][j]>=97&&text[i][j]<=122) {//check if it is a lowercase letter
        if(text[i][j]+13>122) {
          text[i][j]=97+((text[i][j]+13)-123);//add 13 and loop around
        }
        else {
          text[i][j]=text[i][j]+13;//add 13
        }
      }
      else if(text[i][j]>=65&&text[i][j]<=90) {//check if it is an uppercase letter
        if(text[i][j]+13>90) {
          text[i][j]=65+((text[i][j]+13)-91);//add 13 and loop around
        }
        else {
          text[i][j]=text[i][j]+13;//add 13
        }
      }
    }
    printf("%s ", text[i]);
  }
  printf("\n");
  }


int main(int argc, char * argv[]) {
    if(argv[1]==NULL) {
      printf("No input\n");
      return 0;
    }
    argv++;
    rot13(argc-1, argv);
    return 0;
  }

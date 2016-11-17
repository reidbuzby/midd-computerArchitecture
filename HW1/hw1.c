#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
	int step;
	char *test;
	
	if(argv[1]==NULL) {//checks if there is 1 input
		printf("ERROR: Insufficient data provided. Please provide a start and end value\n");
		return 0;
		}
	if(strtol(argv[1], &test, 10)==0) {//checks if first input is an integer
		printf("ERROR: Input must be integers only\n");
		return 0;
		}
	if(argv[2]==NULL) {//checks if there is 2 inputs
		printf("ERROR: Insufficient data provided. Please provide a start and end value\n");
		return 0;
		}
	if(strtol(argv[2], &test, 10)==0) {//checks if second input is an integer
		printf("ERROR: Input must be integers only\n");
		return 0;
		}
	if(strtol(argv[3], &test, 10)==0) {//checks if third input is an integer
		printf("ERROR: Input must be integers only\n");
		return 0;
		}
		
	if(argv[3]==NULL) {//if third input is null defaults to a step of 1
		step = 1;
	}
	else {
		step = atoi(argv[3]);
		}
		
	long start = atoi(argv[1]);
	long end = atoi(argv[2]);
	
	
	if(atoi(argv[2])>99999) {//if miles exceeds table width of 5
		int len = strlen (argv[2]);
		printf("+-------");
		for(int i=0;i<len-5;i++) {//add to first box edge on left
			printf("-");
			}
		char str[20] = {0};
		sprintf(str, "%.2f", atoi(argv[2])*1.61);//get length of kilometers string
		int klen = strlen(str);
		int bool = 0;
		
		if(klen>10) {//if kilometers exceeds table width of 10
			bool = 1;
			printf("+------------");
			for(int i=0;i<klen-10;i++) {//add to first box edge on right
				printf("-");
				}
			printf("+\n");
			}
		else {
			printf("+------------+\n");
		}
		
		printf("| miles ");
		for(int i=0;i<len-5;i++) {//add spaces after miles
			printf(" ");
			}
			
		if(bool==0) {//if kilometers is default length
			printf("| kilometers |\n");
			}
		else {//if greater than default length
			printf("| kilometers ");
			for(int i=0;i<klen-10;i++) {//add spaces after kilometers
					printf(" ");
					}
			printf("|\n");
		}
		printf("+-------");
		
		for(int i=0;i<len-5;i++) {//add to second box edge on left
			printf("-");
			}
			
		if(bool==1) {//if kilometers greater than default length
			printf("+------------");
			for(int i=0;i<klen-10;i++) {//add to second box edge on right
				printf("-");
				}
			printf("+\n");
			}
		else {
			printf("+------------+\n");
		}
		
		for(int i=start;i<end;i+=step) {//loop through all necessary rows
			char str[20] = {0};
			sprintf(str, "%d", i);
			int len2 = strlen(str);
			printf("| ");
			for(int j=0;j<len-len2;j++) {
				printf(" ");//add necessary spaces
				}
			printf("%3d | %10.2f |\n",i,i*1.61);//print conversions
			}
			
		printf("+-------");
		for(int i=0;i<len-5;i++) {
			printf("-");
			}
			
		if(bool==1) {
			printf("+------------");
			for(int i=0;i<klen-10;i++) {//add to second box edge on right
				printf("-");
				}
			printf("+\n");
			}
		else {
			printf("+------------+\n");
			}
		}
		
	else {//if numbers allow to format to default
		printf("+-------+------------+\n| miles | kilometers |\n+-------+------------+\n");
		for(int i=start;i<end;i+=step) {
			printf("| %5d | %10.2f |\n", i, i*1.61);//print conversions
			}
		printf("+-------+------------+\n");
		}
	return 0;
	}
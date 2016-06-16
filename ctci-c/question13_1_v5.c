/*
13.1 
Write a method to print the last K lines of an input file using C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char *argv[]) {
	FILE *fp_input;
	const char filename[] = "/tmp/randomlist.txt";

	fp_input = fopen(filename,"r");
	if (!fp_input) {
		printf("Erorr in opening file\n");
	}

	char buffer[10][100];
	char start = fgetc(fp_input);
	if (start != EOF) {
		int index = 0;
		while (fgetc(fp_input)!= EOF) {
			fgets(buffer[index%10],sizeof(buffer[index%10]),fp_input);
			index = index+1;
		}

		int loop = (index>9)?1:0;
		int breakpt = index%10;
		int startpt = (index>9)?index%10:0;
		do {
			printf("%s",buffer[startpt++]);
			if (loop == 1 && (startpt == 10)) {
				startpt = 0;
				loop = 0;
			}
		}
		while (startpt != breakpt);
	}
	else {
		printf("File is empty\n");
	}

	fclose(fp_input);
	return 0;
}

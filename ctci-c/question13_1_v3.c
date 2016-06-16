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

	char lastline[100];
	char start = fgetc(fp_input);
	if (start != EOF) {
		char chr;
		while (chr != EOF) {
			chr = fgetc(fp_input);
			if (chr == '\n') {
				break;
			}
		}

		if (fgetc(fp_input) != EOF) {
			fseek(fp_input,-2,SEEK_END);
			while (fgetc(fp_input) != '\n') {
				fseek(fp_input,-2,SEEK_CUR);
			}
			fgets(lastline,sizeof(lastline),fp_input);
			printf("%s\n",lastline);
		}
		else {
			fseek(fp_input,0,SEEK_SET);
			fgets(lastline,sizeof(lastline),fp_input);
			printf("%s\n",lastline);
		}
	}
	else {
		printf("File is empty\n");
	}

	fclose(fp_input);
	return 0;
}

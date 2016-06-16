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
		int count = 0;
		while (count != 10) {
			/* Less than 10 lines */
			chr = fgetc(fp_input);
			if (chr == '\n') {
				count++;
			}
			else if (chr == EOF) {
				break;
			}
		}

		if (fgetc(fp_input) != EOF) {
			fseek(fp_input,-2,SEEK_END);
			int revcount = 0;
			while (revcount != 10) {
				/* Last 10 in more than 10 lines */
				fseek(fp_input,-2,SEEK_CUR);
				if (fgetc(fp_input) == '\n') {
					revcount = revcount+1;
				}
			}

			while (revcount > 0) {
				/* Print Last 10 in more than 10 lines */
				fgets(lastline,sizeof(lastline),fp_input);
				printf("%s",lastline);
				revcount--;
			}
		}
		else {
			fseek(fp_input,0,SEEK_SET);
			while (count > 0) {
				/* Print Less than 10 lines */
				fgets(lastline,sizeof(lastline),fp_input);
				printf("%s",lastline);
				count--;
			}
		}
	}
	else {
		printf("File is empty\n");
	}

	fclose(fp_input);
	return 0;
}

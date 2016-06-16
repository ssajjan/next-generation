/*
5.2
Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print
the binary representation. If the number cannot be represented accurately in binary
with at most 32 characters, print "ERROR."
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void printBits(unsigned int num) {
	if (num == 0) {
		printf("Bit pattern is: ");
	}
	else {
		printBits(num/2);
		printf("%d",num%2);
	}
}

void printBitsFraction(double num) {
	static int count = 0;

	count++;
	if (count < 32) {
		if (num != 0) {
			if (num*2 > 1) {
				printf("1");
			}
			else {
				printf("0");
			}
			printBitsFraction(num*2 - floor(num*2));
		}
	}
	else {
		printf("Error\n");
	}
}

int main(int argc, char *argv[]) {
	/*
	printf("Argument count: %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("Argument vector values:%s at %p memory\n", argv[i], argv[i]);
		for (char *j=argv[i]; *j!='\0'; j++) {
			printf("Another way to print argument vector values: "
                               "%c at %p memory\n", *j, j);
		}
	}

	unsigned int num;

	num = pow(2,31);
	printf("Number : %u\n",num);

	num = 1<<31;
	printf("Number : %u\n",num);
	printf("Number(in hex): %x\n",num);
	printBits(num);printf("\n");

	num = pow(2,32)-1;
	printf("Number : %u\n",num);

	num = 0;
	for (int len = 0; len <32; len++) {
		num = num + pow(2,len);
	}
	printf("Number : %u\n",num);

	num = 0;
	for (int len = 0; len <32; len++) {
		num = num + (1<<len);
	}
	printf("Number : %u\n",num);
	printf("Number(in hex): %x\n",num);
	printBits(num);printf("\n");

	num = 0;
	for (int len = 3; len <32; len=len+4) {
		num = num + (1<<len);
	}
	printf("Number : %u\n",num);
	printf("Number(in hex): %x\n",num);
	printBits(num);printf("\n");
	*/

	double num;

	num = 0.72;

	printf("Num: %lf\n",num);

	printf("Bit pattern is: ");printBitsFraction(num);printf("\n");

	return 0;
}

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

bool printBitsFraction(double num, char *bits) {
	int count = 0;

	while (num != 0) {
		count++;
		if (count > 32) {
			break;
		}
		num = num*2;
		if (num >= 1) {
			bits[count-1] = '1';
			num = num - 1;
		}
		else {
			bits[count-1] = '0';
		}
	}

	if (num == 0 && count <= 32) {
		bits[count] = '\0';
		return true;
	}
	else {
		return false;
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
	char bits[32];
	bool status;

	num = (1.0/2) + (1.0/8) + (1.0/32) + (1.0/256) + (1.0/512);

	printf("Num: %lf\n",num);

	status = printBitsFraction(num,bits);

	if (!status) 
		printf("Error\n");
	else 
		printf("Bit pattern is: .%s\n",bits);

	return 0;
}

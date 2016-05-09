/*
5.1
You are given two 32-bit numbers, N andM, and two bit positions, i and j. Write a
method to insert M into Nsuch that M starts at bit j and ends at bit i. You can assume
that the bits j through i have enough space to fit all ofM. That is, ifM= 10011,
you can assume that there are at least 5 bits between j and i. You would not, for
example, have j-3 and i=2, because M could not fully fit between bit 3 and bit 2.
EXAMPLE:
Input: N = 10000000000, M = 10011, i = 2, j = 6
Output: N= 10001001100
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

	unsigned int n = 0;
	n = n + (1<<31) + (1<<28) + (1<< 24) + (1<< 20) + (1<<15) + (1<<10) + (1<<5) + (1<<3) + (1<<1) + (1<<0);
	printBits(n);printf("\n");

	unsigned int m = 0;
	m = m + (1<<4) + (1<<3) + (1<<2) + (1<<1) + (1<<0);
	printBits(m);printf("\n");

	int startBit = 8;
	int endBit = 4;

	unsigned int c, leftc = 0, rightc;
	leftc = ~leftc;
	printBits(leftc);printf("\n");

	leftc = leftc<<(startBit+1);
	printBits(leftc);printf("\n");

	rightc = 1<<endBit;
	printBits(rightc);printf("\n");

	rightc = rightc-1;
	printBits(rightc);printf("\n");

	c = leftc | rightc;
	printBits(c);printf("\n");

        unsigned int checkc = 0;
        for (int index = startBit; index >= endBit; index--) {
                checkc = checkc + (1<<index);
        }
        checkc = ~checkc;
        printBits(checkc);printf("\n");

	n = n&c;
	printBits(n);printf("\n");

	m = m<<endBit;
	printBits(m);printf("\n");

	n = n|m;
	printBits(n);printf("\n");

	return 0;
}

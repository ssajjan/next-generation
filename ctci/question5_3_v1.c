/*
5.3
Given a positive integer, print the next smallest and the next largest number that
have the same number of 7 bits in their binary representation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int count1s(unsigned int num) {
	int count;
	if (num == 0) {
		count = 0;
		return count;
	}
	else {
		count = count1s(num/2);
		if (num % 2 == 1) 
			count++;
		return count;
	}
}

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

        unsigned int num = 0;
        num = num + (1<<31) + (1<<28) + (1<< 24) + (1<< 20) + (1<<15) + (1<<10) + (1<<5) + (1<<3) + (1<<1) + (1<<0);
	printf("Num: %u\n",num);
        printBits(num);printf("\n");

	int num1s = 0;
	num1s = count1s(num);
	printf("Number of 1's: %d\n",num1s);

	unsigned int newnum = num;
	int newnum1s = num1s;
	do {
		newnum = newnum + 1;
		newnum1s = count1s(newnum);
	}
	while (newnum1s != num1s);

	printf("Num larger than %u with same 1s: %u\n",num, newnum);
        printBits(newnum);printf("\n");
	printf("Number of 1's: %d\n",newnum1s);

	newnum = num;
	do {
		newnum = newnum - 1;
		newnum1s = count1s(newnum);
	}
	while (newnum1s != num1s);

	printf("Num smaller than %u with same 1s: %u\n",num,newnum);
        printBits(newnum);printf("\n");
	printf("Number of 1's: %d\n",newnum1s);

	return 0;
}

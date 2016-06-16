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
        //num = num + (1<<31) + (1<<28) + (1<< 24) + (1<< 20) + (1<<15) + (1<<10) + (1<<5);
        num = num + (1<<31) + (1<<29);
	printf("Num: %u\n",num);
        printBits(num);printf("\n");

	int num1s = 0;
	num1s = count1s(num);
	printf("Number of 1's: %d\n",num1s);

	unsigned int mask1 = 0;
	mask1 = mask1 + (1<<2) + (1<<0);

	unsigned int mask2 = 0;
	mask2 = mask2 + (1<<0);

	unsigned int mask;
	unsigned int lmask;

	mask = mask1;
	printf("Mask1: %u\n",mask);
        printBits(mask);printf("\n");

	lmask = mask;
	int index = 1;

	while ((num & lmask) != lmask) {
		if (index > 28) 
			break;
		lmask = mask<<index;
		index++;
	}
	printf("Mask: %u\n",lmask);
        printBits(lmask);printf("\n");

	if (index>28) {
		mask = mask2;
		printf("Mask2: %u\n",mask);
        	printBits(mask);printf("\n");

		lmask = mask;
		index = 1;
        
		while ((num & lmask) != lmask) {
			lmask = mask<<index;
			index++;
		}
		printf("Mask: %u\n",lmask);
                printBits(lmask);printf("\n");
	}

	//first occurence of 1 01-->1 10 for next larger number
	lmask = ~lmask;
        printBits(lmask);printf("\n");

	unsigned int lnum = num;
	lnum = lnum & lmask;
        printBits(lnum);printf("\n");

	unsigned int reqlmask = 0;
	if (mask == mask1) {
		reqlmask = reqlmask + (1<<2) + (1<<1);
        	printBits(reqlmask);printf("\n");
	}
	else {
		reqlmask = reqlmask + (1<<1);
        	printBits(reqlmask);printf("\n");
	}

	reqlmask = reqlmask<<(index-1);
        printBits(reqlmask);printf("\n");

	lnum = lnum | reqlmask;
        printBits(lnum);printf("\n");
	printf("New Num larger than num: %u\n",lnum);

	//first occurence of 10 1-->01 1 for next smaller number
	mask1 = 0;
	mask1 = mask1 + (1<<2) + (1<<0);

	mask2 = 0;
	mask2 = mask2 + (1<<1);

	unsigned int smask;

	mask = mask1;
	printf("Mask1: %u\n",mask);
        printBits(mask);printf("\n");

	smask = mask;
	index = 1;

	while ((num & smask) != smask) {
		smask = mask<<index;
		index++;
		if (index > 28) 
			break;
	}
	printf("Mask: %u\n",smask);
        printBits(smask);printf("\n");

	if (index>28) {
		mask = mask2;
		printf("Mask2: %u\n",mask);
        	printBits(mask);printf("\n");

		smask = mask;
		index = 1;
        
		while ((num & smask) != smask) {
			smask = mask<<index;
			index++;
		}
		printf("Mask: %u\n",smask);
                printBits(smask);printf("\n");
	}

	smask = ~smask;
        printBits(smask);printf("\n");

	unsigned int snum = num;
	snum = snum & smask;
        printBits(snum);printf("\n");

	unsigned int reqsmask = 0;
	if (mask == mask1) {
		reqsmask = reqsmask + (1<<1) + (1<<0);
        	printBits(reqsmask);printf("\n");
	}
	else {
		reqsmask = reqsmask + (1<<0);
        	printBits(reqsmask);printf("\n");
	}

	reqsmask = reqsmask<<(index-1);
        printBits(reqsmask);printf("\n");

	snum = snum | reqsmask;
        printBits(snum);printf("\n");
	printf("New Num smaller than num: %u\n",snum);
	return 0;
}

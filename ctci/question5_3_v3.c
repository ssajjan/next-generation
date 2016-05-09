/*
5.3
Given a positive integer, print the next smallest and the next largest number that
have the same number of bits in their binary representation.
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

int count1s(unsigned int num) {
	int c1 = 0;
	unsigned int c = num;

	while (c != 0) {
		if ( c & 1 == 1) {
			c1++;
		}
		c = c >> 1;
	}
	return c1;
}

unsigned int findNextLargest(unsigned int num) {
	unsigned int c;
	int c0 = 0, c1 = 0;

	c = num;
	while (((c&1) == 0) && (c!=0)) {
		c0++;                  // Find trailing zeroes
		c = c >> 1;
	}

	while ((c&1) == 1) {
		c1++;                  // Find trailing ones
		c = c >> 1;
	}

	printf("C0: %d, C1: %d\n",c0,c1);

	if (c0 + c1 == 31 || c0 + c1 == 0) {
		return 0;
	}

	int p = c0 + c1;                // position of rightmost non trailing zero

	num = num | (1<<p);             // Flip 0 at pth bit
	num = num & (~((1<<p)-1));      // Clear bits to the right of p bit
	num = num | ((1<<(c1-1))-1);    // Add c1-1 1's to the right of p bit
	return num;
}

unsigned int findNextSmallest(unsigned int num) {
	unsigned int c;
	int c0 = 0, c1 = 0;

	c = num;
	while ((c&1) == 1) {
		c1++;                  // Find trailing zeroes
		c = c >> 1;
	}

	while (((c&1) == 0) && (c!=0)) {
		c0++;                  // Find trailing ones
		c = c >> 1;
	}

	printf("C0: %d, C1: %d\n",c0,c1);

	if (c0 + c1 == 31 || c0 + c1 == 0) {
		return 0;
	}

	int p = c0 + c1;                        // position of rightmost non trailing one

	num = num & (~(1<<p));                  // Flip 1 at pth bit
	num = num & (~((1<<p)-1));              // Clear bits to the right of p bit
	num = num | (((1<<(c1+1))-1)<<(c0-1));  // Add c1+1 1's to the right of p bit

	return num;
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
	*/

        unsigned int num = 0;
        //num = num + (1<<31) + (1<<28) + (1<< 24) + (1<< 20) + (1<<15) + (1<<10) + (1<<5);
        //num = num + (1<<31) + (1<<29);
	num = num + (1<<31) + (1<<28) + (1<< 24) + (1<< 20) + (1<<15) + (1<<10) + (1<<5) + (1<<3) + (1<<1) + (1<<0);
	//num = 190;
	printf("Num: %u\n",num);
        printBits(num);printf("\n");

	int num1s = 0;
	num1s = count1s(num);
	printf("Number of 1's: %d\n",num1s);

	unsigned int nextLargeNum = 0;
	nextLargeNum = findNextLargest(num);

	if (nextLargeNum) {
		printf("Next Largest Num after %u with same count 1's: %u\n",num,nextLargeNum);
        	printBits(nextLargeNum);printf("\n");
		num1s = count1s(nextLargeNum);
		printf("Number of 1's: %d\n",num1s);
	}
	else {
		printf("Error in finding next largest num with same number of 1's\n");
	}

	unsigned int nextSmallNum = 0;
	nextSmallNum = findNextSmallest(num);

	if (nextSmallNum) {
		printf("Previous Smallest Num after %u with same count 1's: %u\n",num,nextSmallNum);
        	printBits(nextSmallNum);printf("\n");
		num1s = count1s(nextSmallNum);
		printf("Number of 1's: %d\n",num1s);
	}
	else {
		printf("Error in finding previous Smallest num with same number of 1's\n");
	}

	return 0;
}

/*
5.5
Write a function to determine the number of bits required to convert integer A to
integer B
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

        unsigned int num1,num2,xor,and,sub,add;
        //num = num + (1<<31) + (1<<28) + (1<< 24) + (1<< 20) + (1<<15) + (1<<10) + (1<<5);
        //num = num + (1<<31) + (1<<29);
	num1 = 140;
	printf("Num1: %u\n",num1);
        printBits(num1);printf("\n");

	num2 = 310;
	printf("Num2: %u\n",num2);
        printBits(num2);printf("\n");

	xor = num1^num2;
	printf("Xor: %u\n",xor);
        printBits(xor);printf("\n");

	int count = 0;
	count = count1s(xor);
	printf("Number of bits required for %u to %u: %d\n",num1,num2,count);

	return 0;
}

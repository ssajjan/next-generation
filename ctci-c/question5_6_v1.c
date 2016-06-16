/*
5.6
Write a program to swap odd and even bits in an integer with as few instructions as
possible (e.g., bit 0 and bit! are swapped, bit 2 and bit 3 are swapped, and so on).
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

        unsigned int num,newnum = 0, even = 0,odd = 0;
        num = num + (1<<31) + (1<<28) + (1<< 24) + (1<< 20) + (1<<15) + (1<<10) + (1<<5);
        //num = num + (1<<31) + (1<<29);
	//num = 140;
	printf("Num: %u\n",num);
        printBits(num);printf("\n");

	int index = 0;
	while (index<=30){
		even += (1<<index);
		index = index + 2;
	}
	printf("Even: %x\n",even);
        printBits(even);printf("\n");
	num = even;
	even = even & num;
        printBits(even);printf("\n");
	even = even<<1;
        printBits(even);printf("\n");

	index = 1;
	while (index<=31){
		odd += (1<<index);
		index = index + 2;
	}
	printf("Odd: %x\n",odd);
        printBits(odd);printf("\n");
	odd = odd&num;
        printBits(odd);printf("\n");
	odd = odd>>1;
        printBits(odd);printf("\n");

	newnum = odd | even;
        printBits(newnum);printf("\n");
        printBits(num);printf("\n");
	
	/* Single Line
		return (((num & 0x55555555) << 1 ) | ((num & 0xaaaaaaaa) >> 1))
	*/

	return 0;
}

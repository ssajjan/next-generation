/*
5.8
A monochrome screen is stored as a single array of bytes, allowing eight consec-
utive pixels to be stored in one byte. The screen has width w, where w is divisible
by 8 (that is, no byte will be split across rows). The height of the screen, of course,
can be derived from the length of the array and the width. Implement a function
drawHorizontalLine(byte[] screen, int width, intxl, intx2, inty) which draws a hori-
zontal line from (x 1, y) to (x2, y).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_BYTES 25

struct byte {
	unsigned int bits:8;
};

void printBits(unsigned int num) {
	static int count = 0;
	count++;
        if (num == 0) {
		while (count <= 8) {
			printf("0");
			count++;
		}
		count = 0;
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

void initializeScreen(struct byte screen[]) {
	int count = 0;
	while (count != MAX_BYTES) {
		screen[count++].bits = 0x00;
	}
}

void printScreen(struct byte screen[], int w) {
	int count = 0;
	printf("\n\t");
	while (count != MAX_BYTES) {
		printBits(screen[count++].bits);
		if (count % w == 0) {
			printf("\n\t");
			if (count == MAX_BYTES) {
				printf("\n");
			}
		}
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
	*/

	struct byte screen[MAX_BYTES];
        int width = 5, x1 = 12, x2 = 27, y = 2;

	initializeScreen(screen);
	screen[11].bits = 0x0F;
	screen[12].bits = 0xFF;
	screen[13].bits = 0xF0;
	printScreen(screen, width);

	initializeScreen(screen);

	int byteStart = 0, byteNext = 0, byteEnd = 0;
	byteStart = (x1/8);
	byteStart += width*y;
	byteNext = byteStart + 1;

	byteEnd = (x2/8);
	byteEnd += width*y;

	printf("ByteStart: %d, ByteNext: %d, ByteEnd: %d\n",byteStart,byteNext,byteEnd);

	while (byteNext != byteEnd) {
		screen[byteNext].bits = 0xFF;
		byteNext++;
	}

	int maskStart = 0, maskEnd = 0, startOffset = 0, endOffset = 0;
	startOffset = (x1 % 8);
	maskStart = (1<<startOffset)-1;
	screen[byteStart].bits |= maskStart;

	endOffset = (x2 % 8);
	maskEnd = ~(0xFF>>(endOffset+1));
	screen[byteEnd].bits |= maskEnd;

	printScreen(screen, width);

	return 0;
}

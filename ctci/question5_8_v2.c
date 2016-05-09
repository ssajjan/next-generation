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
        int width = 5, x1 = 7, x2 = 15, y = 2;

	initializeScreen(screen);
	screen[11].bits = 0x0F;
	screen[12].bits = 0xFF;
	screen[13].bits = 0xF0;
	printScreen(screen, width);

	initializeScreen(screen);

	int byteStart = 0, byteEnd = 0, offbyteStart = 0, offbyteEnd = 0;
	struct byte maskbyteStart, maskbyteEnd;
	byteStart = x1/8;
	offbyteStart = x1%8;
	byteEnd = x2/8;
	offbyteEnd = x2%8;

	if (byteStart == byteEnd) {
		/* Same Byte */
		//if (offbyteStart == offbyteEnd) {
		//	maskbyteStart.bits = (0xFF>>(offbyteStart+1))+1;
		//	screen[y*width+byteStart].bits |= maskbyteStart.bits;
		//}
		//else {
			maskbyteStart.bits = 0xFF>>offbyteStart;
			maskbyteEnd.bits = ~(0xFF>>(offbyteEnd+1));
			screen[y*width+byteStart].bits |= (maskbyteStart.bits & maskbyteEnd.bits);
		//}
	}
	//else if (byteStart == byteEnd-1) {
	//	/* Adjacent Bytes */
	//	maskbyteStart.bits = 0xFF>>offbyteStart;
	//	screen[y*width+byteStart].bits |= maskbyteStart.bits;
	//	maskbyteEnd.bits = ~(0xFF>>(offbyteEnd+1));
	//	screen[y*width+byteEnd].bits |= maskbyteEnd.bits;
	//}
	else {
		/* Bytes separated by another byte/s */
		maskbyteStart.bits = 0xFF>>offbyteStart;
		screen[y*width+byteStart].bits |= maskbyteStart.bits;
		maskbyteEnd.bits = ~(0xFF>>(offbyteEnd+1));
		screen[y*width+byteEnd].bits |= maskbyteEnd.bits;

		byteStart++;
		while (byteStart != byteEnd) {
			screen[y*width + byteStart].bits = 0xFF;
			byteStart++;
		}
	}

	printScreen(screen, width);

	return 0;
}

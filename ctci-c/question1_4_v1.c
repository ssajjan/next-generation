/*/Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end of the string to hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in Java, please use a character array so that you can perform this operation in place.) 

Input : "Mr John Smith    " 
Output: "Mr%20Dohn%20Smith"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shiftStrRight(char *startChr,char *endChr) {
	char *swapChr = startChr;
	while (*swapChr != '\0') {
		char temp = *endChr;
		*endChr = *swapChr;
		*swapChr = temp;
		swapChr++;
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

	char *inStrPtr = argv[1];
	if (inStrPtr == NULL) {
		printf("No Input String specified\n");
		exit(1);
	}
	printf("Input String: %s\n", inStrPtr);

	char *startStrPtr = inStrPtr;
	char *endStrPtr = inStrPtr;
	while (*startStrPtr != '\0') {
		startStrPtr++;
		endStrPtr++;
	}
	endStrPtr--;

	startStrPtr = inStrPtr;
	printf("Length of the string:        %ld\n",endStrPtr-startStrPtr+1);

	while (*startStrPtr != '\0') {
		if (*startStrPtr == ' ') {
			*startStrPtr = '0';
			shiftStrRight(startStrPtr,endStrPtr);
			*startStrPtr = '2';
			shiftStrRight(startStrPtr,endStrPtr);
			*startStrPtr = '%';
		}
		startStrPtr++;
	}

	printf("Input String after space addition: %s\n", inStrPtr);

	startStrPtr = inStrPtr;
	endStrPtr = inStrPtr;
	while (*startStrPtr != '\0') {
		startStrPtr++;
		endStrPtr++;
	}
	endStrPtr--;

	startStrPtr = inStrPtr;
	printf("Length of the string:        %ld\n",endStrPtr-startStrPtr+1);
}


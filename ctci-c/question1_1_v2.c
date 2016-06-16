//Implement a algorithm to determine if the string has all unique characters.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getStrLen(char *strPtr) {
        int strLen = 0;
	if (strPtr != NULL) {
		while (*strPtr != '\0') {
			strLen++;
			strPtr++;
		}
	}

	return strLen;
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

	char *inputStrPtr = argv[1];
	if (inputStrPtr == NULL) {
		printf("No Input String specified\n");
		exit(1);
	}
	printf("Input String: %s\n", inputStrPtr);

	int inputStrLen = 0;
	inputStrLen = getStrLen(inputStrPtr);
	printf("Input String Length: %d\n", inputStrLen);

        int flagArray[256] = {};
	for (int index = 0; index < 256; index++) {
		printf("%d,",flagArray[index]);
	}
	printf("\n");

	int strRepChar = 0;
	int algoCount = 0;
        for (char *inputCharPtr = inputStrPtr; *inputCharPtr != '\0'; inputCharPtr++){
		algoCount++;
		if (inputStrLen > 256) {
			printf("Input string length > 256. String can't have unique chars\n");
			strRepChar = 1;
			break;
		}

		int index = *inputCharPtr;
		if (flagArray[index] > 0) {
			printf("Matching characters found. String doesnt have unique characters\n");
			strRepChar = 1;
			break;
		}
		else {
			flagArray[index] = 1;
		}
	}
	if (strRepChar != 1) {
		printf("No matching characters found. String has unique characters\n");
	}

	for (int index = 0; index < 256; index++) {
		printf("%d,",flagArray[index]);
	}
	printf("\n");
	printf("Algorithm Complexity is O(n) or count %d\n", algoCount);
	return 0;
}

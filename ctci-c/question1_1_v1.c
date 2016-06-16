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

	char *testStrPtr = (char *) malloc(sizeof(char));
	if (testStrPtr == NULL) {
		printf("Memory allocation for Test String failed");
		exit(1);
	}

        int testStrLen = 0;
	testStrLen = getStrLen(testStrPtr);
	printf("Test String Length: %d\n", testStrLen);

        int algoCount = 0;
	int strRepChar = 0;
        for (char *inputCharPtr = inputStrPtr; *inputCharPtr != '\0'; inputCharPtr++){
		printf("Input String Character is: %c\n", *inputCharPtr);

		for (char *testCharPtr = testStrPtr; *testCharPtr != '\0'; testCharPtr++) {
			algoCount++;
			printf("Test String Character is: %c\n", *testCharPtr);
			if (*inputCharPtr == *testCharPtr) {
				printf("String sequence doesnt have unique characters\n");
				strRepChar = 1;
				break;
			}
		}
		if (strRepChar == 1) {
			break;
		}

		testStrPtr = (char *) realloc(testStrPtr,getStrLen(testStrPtr)*sizeof(char)+1);
		//Create string for append
		char inputStrApp[1];
		inputStrApp[0] = *inputCharPtr;
		inputStrApp[1] = '\0';
		strcat(testStrPtr,inputStrApp);

		printf("--------------------------------------------------------\n");
		printf("Test String is: %s\n", testStrPtr);
	}
	if (strRepChar == 0) {
		printf("String Sequence have unique characters\n");
	}

	printf("Algorithm Complexity with %d counts is O(n^2)\n",algoCount);
        free(testStrPtr);
	return 0;
}

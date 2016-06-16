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

	int algoCount = 0;
	int strRep = 0;
	int checker = 0;
        for (char *inputCharPtr = inputStrPtr; *inputCharPtr != '\0'; inputCharPtr++){
		algoCount++;
		int inputCharValue = *inputCharPtr - 'a';
		printf("inputCharValue: %d,",inputCharValue);
		printf("checker: %d\n",checker);
		if ((checker & (1<<inputCharValue)) > 0) {
			printf("Matching character found. String is not unique\n");
			strRep = 1;
			break;
		}
		else {
			checker |= (1<<inputCharValue);
		}
	}
	if (strRep == 0) {
		printf("No matching character found. String is Unique\n");
	}

	printf("Algorithm Complexity is O(n) or count %d\n", algoCount);
	return 0;
}

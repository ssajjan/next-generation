//Implement a function void reverse(char *str) which reverses a null terminated string.

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
void swap(char *a, char *b) {
	// Using 3 variables
	//char temp = *a;
	//*a = *b;
	//*b = temp;

	// Using 2 variables
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void reverse(char *str) {
	printf("In reverse function\n");
	int strLen = getStrLen(str);
	for (int index = 0; index != strLen/2; index++) {
		swap(&str[index],&str[strLen-1-index]);
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

	char *inputStrPtr = argv[1];
	if (inputStrPtr == NULL) {
		printf("No Input String specified\n");
		exit(1);
	}
	printf("Input String: %s\n", inputStrPtr);

	int inputStrLen = 0;
	inputStrLen = getStrLen(inputStrPtr);
	printf("Input String Length: %d\n", inputStrLen);

	reverse(inputStrPtr);
	printf("Reversed String: %s\n", inputStrPtr);
	return 0;
}

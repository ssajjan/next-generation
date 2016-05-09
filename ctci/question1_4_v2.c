/*/Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end of the string to hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in Java, please use a character array so that you can perform this operation in place.) 

Input : "Mr John Smith    " 
Output: "Mr%20Dohn%20Smith"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	char *startStrPtr = inStrPtr;
	int strLen = 0;
	while (*startStrPtr != '\0') {
		strLen++;
		startStrPtr++;
	}

	printf("Input String: %s\n", inStrPtr);
	printf("Input String Length: %d\n", strLen);

	char *backupStrPtr = malloc((strLen)*sizeof(char));

	int i=0;
	int j=0;
	while (i < strLen) {
		if (inStrPtr[j] == ' ') {
			backupStrPtr[i] = '%';
			backupStrPtr[i+1] = '2';
			backupStrPtr[i+2] = '0';
			i=i+2;
		}
		else {
			backupStrPtr[i] = inStrPtr[j];
		}
		j++;
		i++;
	}

	printf("Input String after space editng: %s\n", backupStrPtr);

	free(backupStrPtr);
}


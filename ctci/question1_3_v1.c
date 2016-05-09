//Given two strings, write a method to decide if one string is a permutation of the other.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

bool isPermut(char *str, char *subsetStr) {
	printf("In isPermut\n");
	printf("Input String: %s\n", str);
	printf("Subset Input String: %s\n", subsetStr);

	int chrmatch = 0;
	for (char *subchr = subsetStr; *subchr != '\0'; subchr++) {
		for (char *chr = str; *chr != '\0'; chr++) {
			if (*subchr == *chr) {
				printf("%c,%c\n",*subchr,*chr);
				chrmatch = 1;
				break;
			}
			else {
				chrmatch = 0;
			}
		}
		if (chrmatch == 0)
			return false;
	}
	return true;
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

	char *inputStrPtr1 = argv[1], *inputStrPtr2 = argv[2];
	if ((inputStrPtr1 == NULL) || (inputStrPtr2 == NULL)) {
		printf("Either Input String or Subset Input String not specified\n");
		exit(1);
	}
	printf("Input String: %s\n", inputStrPtr1);
	printf("Subset Input String: %s\n", inputStrPtr2);

	int inputStrLen1 = 0, inputStrLen2 = 0;
	inputStrLen1 = getStrLen(inputStrPtr1);
	inputStrLen2 = getStrLen(inputStrPtr2);
	printf("Input String Length: %d\n", inputStrLen1);
	printf("Subset Input String Length: %d\n", inputStrLen2);

	bool permutCheck = false;
	permutCheck = isPermut(inputStrPtr1,inputStrPtr2);

	if (permutCheck)
		printf("Subset Input String: %s is a permutation of Input String: %s\n",inputStrPtr2, inputStrPtr1);
	else
		printf("Subset Input String: %s is not a permutation of Input String: %s\n",inputStrPtr2, inputStrPtr1);
	return 0;
}

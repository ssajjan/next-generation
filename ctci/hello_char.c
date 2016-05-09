// Characterize variable lenght character arrays

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

	int strLen = sizeof(argv[1])/sizeof(char);
	printf("Input String length is: %d\n",strLen);

	char *strPtr = argv[1];
	if (strPtr == NULL) {
		printf("No Input String specified\n");
		exit(1);
	}
	printf("Input String: %s\n", strPtr);

	char *mallocPtr = malloc(strLen*sizeof(char));
	memset(mallocPtr,1,strLen*sizeof(char)-1);
	mallocPtr[strLen] = '\0';
	for (int index = 0; index < 2*strLen; index++) {
		printf("%p--%c\n",mallocPtr+index,*(mallocPtr+index));
	}
	printf("Pointers are %p\n", mallocPtr);
	free(mallocPtr);

	return 0;
}

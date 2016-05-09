/*Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the orig-
inal string, your method should return the original string.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

	int mask[256] = {};

	char *strPtr = inStrPtr;
	while (*strPtr != '\0') {
		mask[*strPtr++]++;
	}

	int strCompLen = 0;
	for (int index = 0; index<256; index++) {
		printf("%d,",mask[index]);
		if (mask[index] != 0) { 
			strCompLen++;
			strCompLen+= floor(log10(mask[index])) + 1;
		}
	}
	printf("\n");

	printf("Compressed string Length is %d\n",strCompLen);
	if (strCompLen < strLen) {
		char *strComp = malloc(strCompLen*sizeof(char));
        
		int j = 0;
		for (int index = 0; index<256; index++) {
			if (mask[index] != 0) {
				strComp[j] = index;
				if (floor(log10(mask[index])) >= 2) {
					strComp[j+1] = mask[index]/100+48;
					strComp[j+2] = (mask[index]%100)/10+48;
					strComp[j+3] = (mask[index]%100)%10+48;
					j=j+4;
				}
				else if(floor(log10(mask[index])) < 2 && floor(log10(mask[index])) >= 1) {
					strComp[j+1] = mask[index]/10+48;
					strComp[j+2] = mask[index]%10+48;
					j=j+3;
				}
				else {
					strComp[j+1] = mask[index]+48;
					j=j+2;
				}
			}
		}
		strComp[strCompLen] = '\0';
        
		printf("Compressed string is %s\n", strComp);
		free(strComp);
	}
	else {
		printf("No compression possible\n");
		printf("Original String is %s\n",inStrPtr);
	}

	return 0;
}

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

	char *strPtr = argv[1];
	if (strPtr == NULL) {
		printf("No Input String specified\n");
		exit(1);
	}

	char *startStrPtr = strPtr;
	int strLen = 0;
	while (*startStrPtr != '\0') {
		strLen++;
		startStrPtr++;
	}

	printf("Input String: %s\n", strPtr);
	printf("Input String Length: %d\n", strLen);

	int strCompLen = 0;
	char lastChar;
	if (strPtr[0] != '\0') { 
		lastChar = strPtr[0];
	}
	else {
		printf("Empty String given as input\n");
		exit(1);
	}
	int count = 0;
	for (int index=0; strPtr[index]!= '\0'; index++) {
		if (lastChar == strPtr[index]) {
			count++;
		}
		else {
			strCompLen++;
			strCompLen+=floor(log10(count))+1;
			lastChar = strPtr[index];
			count=1;
		}
	}
	strCompLen++;
	strCompLen+=floor(log10(count))+1;
	printf("Compressed string length is: %d\n",strCompLen);

	if (strCompLen < strLen) {
		char *strComp = malloc(strCompLen*sizeof(char));;
		int j = 0;

		lastChar = strPtr[0];
		count = 0;
		for (int index=0; strPtr[index]!= '\0'; index++) {
			if (lastChar == strPtr[index]) {
				count++;
			}
			else {
				strComp[j] = lastChar;

				int strIntLen = floor(log10(count))+1;
				char *strInt = malloc(strIntLen*sizeof(char));
				snprintf(strInt,strIntLen*sizeof(char)+1,"%d", count);
				for (int i = 0; strInt[i] != '\0'; i++) {
					strComp[j+i+1] = strInt[i];
				}
				free(strInt);

				j=j+1+strIntLen;
				lastChar = strPtr[index];
				count=1;
			}
		}
		strComp[j] = lastChar;
		int strLastIntLen = floor(log10(count))+1;
		char *strLastInt = malloc(strLastIntLen*sizeof(char));
		snprintf(strLastInt,strLastIntLen*sizeof(char)+1,"%d", count);
		for (int i = 0; strLastInt[i] != '\0'; i++) {
			strComp[j+i+1] = strLastInt[i];
		}
		free(strLastInt);
		j=j+1+strLastIntLen;

		printf("Compressed string is: %s\n",strComp);
		free(strComp);
	}
	else {
		printf("No compression possible\n");
		printf("Original String is %s\n",strPtr);
	}

	return 0;
}

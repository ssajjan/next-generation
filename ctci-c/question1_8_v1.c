/*
Assume you have a method isSubstring which checks if one word is a
substring of another. Given two strings, si and s2, write code to check if s2 is
a rotation of si using only one call to isSubstring (e.g.,"waterbottle"is a rota-
tion of "erbottlewat").
*/

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

bool isPermut(char *str, int strLen, char *strSub, int strSubLen) {
	//printf("In isPermut\n");
	//printf("Input String: %s\n", str);
	//printf("Subset Input String: %s\n", strSub);

	//printf("Input String: %s\n", str);
	//printf("Input String Pointer: %p\n", str);
	//printf("Subset Input String: %s\n", strSub);
	//printf("Subset Input String Pointer: %p\n", strSub);

	//char strMask[256] = {};
	//for (char *chr=str; *chr!='\0'; chr++){
	//	strMask[*chr]++;
	//}

	//for (int index = 0; index<256; index++){
	//	printf("%d,",strMask[index]);
	//}
	//printf("\n");

	//for (char *chrSub=strSub; *chrSub!='\0'; chrSub++){
	//	if (--strMask[*chrSub]<0) {
	//		//printf("More number of characters found in Subset String than Input String\n");
	//		return false;
	//	}
	//}

	//for (int index = 0; index<256; index++){
	//	printf("%d,",strMask[index]);
	//}
	//printf("\n");

	//if (strstr(str,strSub)) 
	//	return true;
	//else
	//	return false;
	
	bool substr = false;
	int index = 0;
	for (int i=0; i<strLen; i++) {
		if (index != strSubLen) {
			//printf("%c,%c\n",str[i],strSub[index]);
			if (strSub[index] == str[i]) {
				substr = true;
				index++;
			}
			else {
				substr = false;
				index = 0;
			}
		}
		else {
			break;
		}
	}

	if (index != strSubLen)
		substr = false;

	return substr;
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

	int inputStrLen1 = 0;
	for (char *chrPtr = argv[1]; *chrPtr!= '\0'; chrPtr++) {
		inputStrLen1++;
	}
	char inputStrPtr1[inputStrLen1];
	int index = 0;
	for (char *chrPtr = argv[1]; *chrPtr!= '\0'; chrPtr++) {
		inputStrPtr1[index++] = *chrPtr;
	}

	int inputStrLen2 = 0;
	for (char *chrPtr = argv[2]; *chrPtr!= '\0'; chrPtr++) {
		inputStrLen2++;
	}
	char inputStrPtr2[inputStrLen2];
	for (char *chrPtr = argv[2], index = 0; *chrPtr!= '\0'; chrPtr++) {
		inputStrPtr2[index++] = *chrPtr;
	}

	if ((inputStrPtr1 == NULL) || (inputStrPtr2 == NULL)) {
		printf("Either Input String or Subset Input String not specified\n");
		exit(1);
	}

	//inputStrLen1 = getStrLen(inputStrPtr1);
	//inputStrLen2 = getStrLen(inputStrPtr2);
	printf("Input String: %s\n", inputStrPtr1);
	//printf("Input String Pointer: %p\n", inputStrPtr1);
	//printf("Input String Length: %d\n", inputStrLen1);
	//printf("Input String Pointer+%d: %p\n", inputStrLen1,inputStrPtr1+inputStrLen1);
	printf("Subset Input String: %s\n", inputStrPtr2);
	//printf("Input String Pointer: %p\n", inputStrPtr2);
	//printf("Subset Input String Length: %d\n", inputStrLen2);

	bool permutCheck = false;
	//printf("Boolean value is %d and has size %ld at pointer %p\n",permutCheck,sizeof(permutCheck),&permutCheck);
	if (inputStrLen1==inputStrLen2) {
		strcat(inputStrPtr1,inputStrPtr1);
		permutCheck = isPermut(inputStrPtr1,inputStrLen1*2,inputStrPtr2,inputStrLen2);
	}
	else {
		printf("Length of input String and substring is not same\n");
	}

	if (permutCheck)
		printf("Subset Input String: %s is a rotation of Input String: %s\n",inputStrPtr2, inputStrPtr1);
	else
		printf("Subset Input String: %s is not a rotation of Input String: %s\n",inputStrPtr2, inputStrPtr1);
	return 0;
}

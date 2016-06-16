/*Given an image represented by an NxN matrix, where each pixel in the image is
4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
place?
*/

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

	int n=4,num=1;
	int imgArr[n][n];
	printf("Initial image of size %ld bytes\n",sizeof(imgArr));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			imgArr[i][j] = num++;
			printf("%d\t",imgArr[i][j]);
		}
		printf("\n");
	}

	int imgArrRot[n][n];
	printf("Rotated image of size %ld bytes\n",sizeof(imgArrRot));
	for (int i = 0; i < n; i++) {
		int index = n-1;
		for (int j = 0; j < n; j++) {
			imgArrRot[i][j] = imgArr[index][i];
			printf("%d\t",imgArrRot[i][j]);
			index--;
		}
		printf("\n");
	}

	return 0;
}

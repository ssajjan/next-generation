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

	int n=6,num=1;
	int imgArr[n][n];
	printf("Initial image of size %ld bytes\n",sizeof(imgArr));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			imgArr[i][j] = num;
			printf("%d\t",imgArr[i][j]);
		}
		num++;
		printf("\n");
	}

	for (int layer = 0; layer < n/2; layer++) {
		//int offset = layer;
		for (int j = layer; j < n-layer-1; j++) {
			//top    = imgArr[layer][j];         //top
			//printf("top: (%d,%d) with value: %d\n",layer,j,imgArr[layer][j]);
			//right  = imgArr[j][n-1-layer];     //right
			//printf("right: (%d,%d) with value: %d\n",j,n-1-layer,imgArr[j][n-1-layer]);
			//bottom = imgArr[n-1-layer][j];     //bottom
			//printf("bottom: (%d,%d) with value: %d\n",n-1-layer,n-1-layer-j+offset,imgArr[n-1-layer][n-1-layer-j+offset]);
			//left   = imgArr[j][layer];         //left
			//printf("left: (%d,%d) with value: %d\n",n-1-layer-j+offset,layer,imgArr[n-1-layer-j+offset][layer]);

			int temp             = imgArr[j][n-1-layer];
			imgArr[j][n-1-layer] = imgArr[layer][j];
			//imgArr[layer][j]     = imgArr[n-1-layer-j+offset][layer];
			imgArr[layer][j]     = imgArr[n-1-j][layer];
			//imgArr[n-1-layer-j+offset][layer]     = imgArr[n-1-layer][n-1-layer-j+offset];
			imgArr[n-1-j][layer]     = imgArr[n-1-layer][n-1-j];
			//imgArr[n-1-layer][n-1-layer-j+offset] = temp;
			imgArr[n-1-layer][n-1-j] = temp;

			//printf("New top: (%d,%d) with value: %d\n",layer,j,imgArr[layer][j]);
			//printf("New right: (%d,%d) with value: %d\n",j,n-1-layer,imgArr[j][n-1-layer]);
			//printf("New bottom: (%d,%d) with value: %d\n",n-1-layer,n-1-layer-j+offset,imgArr[n-1-layer][n-1-layer-j+offset]);
			//printf("New left: (%d,%d) with value: %d\n",n-1-layer-j+offset,layer,imgArr[n-1-layer-j+offset][layer]);
		}
		//printf("----\n");
	}
 
	printf("CLockwise Rotated image of size %ld bytes\n",sizeof(imgArr));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t",imgArr[i][j]);
		}
		printf("\n");
	}

 	return 0;
}

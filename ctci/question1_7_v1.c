/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row
and column are set to 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void setRowColZero (int *arrPtr, int rows, int cols, int flagIndex) {
	int indexI = flagIndex / cols;
	int indexJ = flagIndex % cols;

	for (int j = 0; j < cols; j++) {
		*(arrPtr + indexI*cols + j) = 0; 
	}

	for (int i = 0; i < rows; i++) {
		*(arrPtr + i*cols + indexJ) = 0; 
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

	int m=8,n=6,num=2;
	int arr[m][n];
	printf("Initial array\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = abs(num);
			num--;
			//arr[i][j] = i==j?1:0;
			printf("%d\t",arr[i][j]);
		}
		num=num+5*(i+1);
		printf("\n");
	}

	int flagArrLen = 2;
	int *flagArr = (int *)malloc(flagArrLen*sizeof(int));
	if (flagArr == NULL) {
		printf("Error assigning memory for flag array\n");
		exit(1);
	}
	else {
		printf("Flag array pointer is: %p\n",flagArr);
	}
	memset(flagArr,0,flagArrLen*sizeof(int));

	int count = 0;
	int flagIndex = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				flagArr[flagIndex] = count;
				flagIndex++;

				if (flagIndex == flagArrLen) {
					flagArrLen *= 2;
					int *flagArrTemp = (int *)realloc(flagArr,flagArrLen*sizeof(int));
					if (flagArrTemp == NULL) {
						printf("Error re-assigning memory for flag array\n");
						exit(1);
					}
					else {
						printf("Flag array temp pointer is: %p\n",flagArrTemp);
						printf("Flag array length is: %d\n",flagArrLen);
						flagArr = flagArrTemp;
					}
				}
			}
			count++;
		}
	}

	printf("Flag array index is: %d\n",flagIndex);
	for (int i = 0; i < flagIndex; i++) {
		setRowColZero(arr,m,n,flagArr[i]);
	}

	printf("Array after processing 0's\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}

	free(flagArr);
 	return 0;
}

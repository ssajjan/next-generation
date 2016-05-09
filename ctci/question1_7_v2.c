/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row
and column are set to 0.
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

	int m=5,n=5,num=2;
	int arr[m][n];
	printf("Initial array\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = abs(num);
			num--;
			arr[i][j] = i==j?0:1;
			printf("%d\t",arr[i][j]);
		}
		num=num+5*(i+1);
		printf("\n");
	}

	int rows[m];
	memset(rows,0,m*sizeof(int));
	int cols[n];
	memset(cols,0,n*sizeof(int));

	int rowIndex=0,colIndex=0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				rows[rowIndex]= 1;
				cols[colIndex]= 1;
				printf("Column index: %d\n",colIndex);
			}
			colIndex++;
		}
		colIndex = 0;
		rowIndex++;
	}

	printf("Row flag array is:\n");
	for (int index=0; index<m; index++) {
		printf("%d,",rows[index]);
	}
	printf("\n");

	printf("Col flag array is:\n");
	for (int index=0; index<n; index++) {
		printf("%d,",cols[index]);
	}
	printf("\n");

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (rows[i]==1 || cols[j]==1) {
				arr[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}

 	return 0;
}

/*
	Array of pointers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initArr(int **arrp) {
	printf("Array pointer start is: %p\n",arrp);
	printf("Array pointer start is: %p\n",*arrp);
	printf("Array pointer start is: %p\n",arrp[0]);
	printf("Array pointer start is: %p\n",*arrp[0]);
	printf("Array pointer start is: %p\n",&arrp[0]);
	printf("Array pointer start is: %p\n",arrp+0);
	printf("Array pointer start is: %p\n",arrp[5]);
	printf("Array pointer start is: %p\n",&arrp[5]);
	printf("Array pointer start is: %p\n",arrp+5);
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

	int *arrp[10] = {1,2,3,4,5,6,7,8,9,10};

	printf("Array pointer start is: %p\n",arrp);
	printf("Array pointer start is: %p\n",&arrp);
	printf("Array pointer start is: %p\n",arrp[0]);
	printf("Array pointer start is: %p\n",&arrp[0]);
	printf("Array pointer start is: %p\n",arrp[5]);
	printf("Array pointer start is: %p\n",&arrp[5]);

	initArr(arrp);

	return 0;
}

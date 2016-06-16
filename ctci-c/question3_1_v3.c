/*
3.1 
Describe how you could use a single array to implement three stacks
DYNAMIC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 12
int indexStack[MAX_LEN/3] = {};

void printArr(int *arr) {
	printf("Array is: \n");
	for (int index = 0; index < MAX_LEN; index++) {
		printf("%d,",arr[index]);
	}
	printf("\n");
}

bool pushArr(int *arr, int stack, int val) {
        if (indexStack[stack-1] < MAX_LEN/3) {
                arr[indexStack[stack-1]++ + ((stack-1)*MAX_LEN/3)] = val;
		return true;
        }
        else {
                printf("Stack array full\n");
                return false;
        }
}

int popArr(int *arr, int stack) {
        if (indexStack[stack-1] > 0) {
                return arr[--indexStack[stack-1] + ((stack-1)*MAX_LEN/3)];
		/* Can also clear the top value of the stack */
        }
        else {
                printf("Stack array empty\n");
                return indexStack[stack-1];
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

	int arr[MAX_LEN] = {};

	pushArr(arr,1,10);
	pushArr(arr,1,20);
	pushArr(arr,1,30);
	pushArr(arr,2,10);
	pushArr(arr,2,20);
	pushArr(arr,2,30);
	pushArr(arr,3,10);
	pushArr(arr,3,20);
	pushArr(arr,3,30);
	pushArr(arr,1,40);
	pushArr(arr,2,40);
	pushArr(arr,3,40);
	printArr(arr);
	popArr(arr,1);
	popArr(arr,2);
	popArr(arr,3);
	popArr(arr,1);
	popArr(arr,2);
	popArr(arr,3);
	popArr(arr,1);
	popArr(arr,2);
	popArr(arr,3);
	popArr(arr,1);
	popArr(arr,2);
	popArr(arr,3);
	printArr(arr);
	pushArr(arr,1,40);
	pushArr(arr,2,50);
	pushArr(arr,3,60);
	pushArr(arr,1,40);
	pushArr(arr,2,50);
	pushArr(arr,3,60);
	pushArr(arr,1,40);
	pushArr(arr,2,50);
	pushArr(arr,3,60);
	pushArr(arr,1,70);
	pushArr(arr,2,70);
	pushArr(arr,3,70);
	printArr(arr);
	
	return 0;
}

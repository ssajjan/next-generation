/*
3.6 
Write a program to sort a stack in ascending order (with biggest items on top).
You may use at most one additional stack to hold items, but you may not copy the
elements into any other data structure (such as an array). The stack supports the
following operations: push, pop, peek, and isEmpty.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 20
int indexStack[MAX_LEN/10] = {};

void print(int *arr) {
	printf("\nArray is: ");
	for (int index = 0; index < MAX_LEN; index++) {
		if (index % 10 == 0)
			printf("\n");
		printf("%d,",arr[index]);
	}
	printf("\n");
}

bool push(int *arr, int stack, int val) {
        if (indexStack[stack-1] < MAX_LEN/2) {
                arr[indexStack[stack-1]++ + ((stack-1)*MAX_LEN/2)] = val;
		return true;
        }
        else {
                printf("Stack array full\n");
                return false;
        }
}

int pop(int *arr, int stack) {
	int val;
        if (indexStack[stack-1] > 0) {
                val = arr[--indexStack[stack-1] + ((stack-1)*MAX_LEN/2)];
		arr[indexStack[stack-1] + ((stack-1)*MAX_LEN/2)] = 0;
		return val;
		/* Can also clear the top value of the stack */
        }
        else {
                printf("Stack array empty\n");
                return indexStack[stack-1];
        }
}

int top(int *arr, int stack) {
	int val;
        if (indexStack[stack-1] > 0) {
                val = arr[--indexStack[stack-1] + ((stack-1)*MAX_LEN/2)];
		indexStack[stack-1]++;
		return val;
        }
        else {
                printf("Stack array empty\n");
                return indexStack[stack-1];
        }
}

bool isEmpty(int *arr, int stack) {
	if (indexStack[stack-1] > 0)
		return false;
	else
		return true;
}

void sortRec(int *arr, int stack, int limit) {
	int val, min;

	if (limit < MAX_LEN/2-1) {
		min = top(arr,stack);

		while (indexStack[stack-1] > limit) {
			val = pop(arr,stack);
			if (val < min) {
				min = val;
			}
			push(arr,stack+1,val);
		}
		push(arr,stack,min);

		while (!isEmpty(arr,stack+1)) {
			val = pop(arr,stack+1);
			if (val != min) {
				push(arr,stack,val);
			}
		}

		sortRec(arr,stack,limit+1);
	}
	else {
		printf("Sorting complete\n");
	}
}

void sort(int *arr, int stack) {
	int limit = 0;
	sortRec(arr,stack,limit);
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

	push(arr,1,4);
	push(arr,1,9);
	push(arr,1,3);
	push(arr,1,7);
	push(arr,1,1);
	push(arr,1,2);
	push(arr,1,5);
	push(arr,1,10);
	push(arr,1,8);
	push(arr,1,6);
	print(arr);

	sort(arr,1);

	print(arr);

	return 0;
}

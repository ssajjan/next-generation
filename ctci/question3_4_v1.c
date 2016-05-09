/*
3.4 
In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of
different sizes which can slide onto any tower. The puzzle starts with disks sorted
in ascending order of size from top to bottom (i.e., each disk sits on top of an even
larger one). You have the following constraints:
(T) Only one disk can be moved at a time.
(2) A disk is slid off the top of one tower onto the next rod.
(3) A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first tower to the last using Stacks.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 30
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
        if (indexStack[stack-1] < MAX_LEN/3) {
                arr[indexStack[stack-1]++ + ((stack-1)*MAX_LEN/3)] = val;
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
                val = arr[--indexStack[stack-1] + ((stack-1)*MAX_LEN/3)];
		arr[indexStack[stack-1] + ((stack-1)*MAX_LEN/3)] = 0;
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
                val = arr[--indexStack[stack-1] + ((stack-1)*MAX_LEN/3)];
		indexStack[stack-1]++;
		return val;
        }
        else {
                printf("Stack array empty\n");
                return indexStack[stack-1];
        }
}

void moveDisksRec(int *arr, int origStack, int nthDisk, int buffStack, int reqStack) {
	int val;
	if (nthDisk == 1) {
		val = pop(arr,origStack);
		push(arr,reqStack,val);
		print(arr);
	}
	else {
		moveDisksRec(arr,origStack,nthDisk-1,reqStack, buffStack);

		val = pop(arr,origStack);
		push(arr,reqStack,val);
		print(arr);

		moveDisksRec(arr,buffStack, nthDisk-1,origStack,reqStack);
	}
}

void moveDisks(int *arr) {
	int nthDisk = indexStack[0];
	moveDisksRec(arr, 1, nthDisk, 2, 3);
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

	push(arr,1,100);
	push(arr,1,90);
	push(arr,1,80);
	push(arr,1,70);
	push(arr,1,60);
	push(arr,1,50);
	push(arr,1,40);
	push(arr,1,30);
	push(arr,1,20);
	push(arr,1,10);

	print(arr);

	moveDisks(arr);

	print(arr);

	return 0;
}

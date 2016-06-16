/*
3.5 
Implement a MyQueue class which implements a queue using two stacks.
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

bool enqueue(int *arr, int val) {
	return push(arr,1,val);
}

int dequeue(int *arr) {
	int val, retVal;

	while (indexStack[0] > 0) {
		val = pop(arr,1);
		push(arr,2,val);
	}

	print(arr);
	retVal = pop(arr,2);

	while (indexStack[1] > 0) {
		val = pop(arr,2);
		push(arr,1,val);
	}

	return retVal;
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

	enqueue(arr,1);
	print(arr);
	enqueue(arr,2);
	print(arr);
	enqueue(arr,3);
	print(arr);
	enqueue(arr,4);
	print(arr);
	printf("Dequeue: %d\n",dequeue(arr));
	print(arr);
	printf("Dequeue: %d\n",dequeue(arr));
	print(arr);
	enqueue(arr,5);
	print(arr);
	enqueue(arr,6);
	print(arr);
	enqueue(arr,7);
	print(arr);
	printf("Dequeue: %d\n",dequeue(arr));
	print(arr);
	printf("Dequeue: %d\n",dequeue(arr));
	print(arr);
	printf("Dequeue: %d\n",dequeue(arr));
	print(arr);
	printf("Dequeue: %d\n",dequeue(arr));
	print(arr);
	printf("Dequeue: %d\n",dequeue(arr));
	print(arr);
	printf("Dequeue: %d\n",dequeue(arr));
	print(arr);
	enqueue(arr,100);
	print(arr);
	enqueue(arr,101);
	print(arr);
	enqueue(arr,102);
	print(arr);
	enqueue(arr,103);
	print(arr);
	enqueue(arr,104);
	print(arr);
	enqueue(arr,105);
	print(arr);
	enqueue(arr,106);
	print(arr);
	enqueue(arr,107);
	print(arr);
	enqueue(arr,108);
	print(arr);
	enqueue(arr,109);
	print(arr);
	enqueue(arr,110);
	print(arr);
	printf("Dequeue: %d\n",dequeue(arr));
	print(arr);
	enqueue(arr,110);
	print(arr);
	printf("Dequeue: %d\n",dequeue(arr));
	print(arr);

	return 0;
}

/*
3.1 
How would you design a stack which, in addition to push and pop, also has a
function min which returns the minimum element? Push, pop and min should all
operate in 0(1) time.
*/

/*Implemented as an array with index at arr[0] and rest of the stack from arr[1] to arr[len-1]
MInimum is contained in an separate array stack, which only addson when new minimum is added.
and pops the minimum out when current top value popped out is equal to the minimum.
Space saved by not pushing to min stack for each value pushed to main stack but loss happens when we need
to define an array of same size statistically before.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 10

int min[MAX_LEN] = {};

void printArr(int *arr) {
	printf("Array is: \n");
	for (int index = 0; index < MAX_LEN; index++) {
		printf("%d,",arr[index]);
	}
	printf("\n");
}

int topArr(int *arr) {
        if (arr[0] > 0) {
		return arr[arr[0]];
        }
        else {
                printf("Stack array empty\n");
                return arr[0];
        }
}

bool pushArr(int *arr, int val) {
        if (arr[0] < MAX_LEN) {
		if (arr[0] == 0 || val <= topArr(min)) {
			min[++min[0]] = val;
		}
                arr[++arr[0]] = val;
		return true;
        }
        else {
                printf("Stack array full\n");
                return false;
        }
}

int popArr(int *arr) {
	int val;
        if (arr[0] > 0) {
		val = arr[arr[0]];
		arr[arr[0]--] = 0;
		if (val == topArr(min)) {
			min[min[0]--] = 0;
		}
                return val;
        }
        else {
                printf("Stack array empty\n");
                return arr[0];
        }
}

int minArr(int *arr) {
	return topArr(min);
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

	pushArr(arr,100);
	printf("Min: %d\n",minArr(arr));
	pushArr(arr,11);
	printf("Min: %d\n",minArr(arr));
	pushArr(arr,20);
	printf("Min: %d\n",minArr(arr));
	pushArr(arr,10);
	printf("Min: %d\n",minArr(arr));
	printArr(arr);
	printArr(min);
	printf("Min: %d\n",minArr(arr));
	popArr(arr);
	printf("Min: %d\n",minArr(arr));
	popArr(arr);
	printf("Min: %d\n",minArr(arr));
	popArr(arr);
	printf("Min: %d\n",minArr(arr));
	printArr(arr);
	printArr(min);
	printf("Min: %d\n",minArr(arr));
	pushArr(arr,20);
	printf("Min: %d\n",minArr(arr));
	pushArr(arr,15);
	printf("Min: %d\n",minArr(arr));
	pushArr(arr,5);
	printf("Min: %d\n",minArr(arr));
	printArr(arr);
	printArr(min);
	printf("Min: %d\n",minArr(arr));
	
	return 0;
}

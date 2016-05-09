/*
9.3
A magic index in an array A[l.. .n-l] is defined to be an index such that A[i] =
i. Given a sorted array of distinct integers, write a method to find a magic index, if
one exists, in array A.
FOLLOW UP
What if the values are not distinct?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define N 20 

int findMagicIndexOld(int *arr, int len) {
	int index = 0;
	while (index < len) {
		if (arr[index] == index) {
			break;
		}
		index++;
	}
	return index;
}

int findMagicIndex(int *arr, int leftindex, int rightindex) {
	if ((arr[leftindex] > leftindex) || (arr[rightindex] < rightindex)) {
		return -1;
	}

	int midindex = (leftindex+rightindex)/2;
	printf("Mid index: %d\n",midindex);

	if (arr[midindex] < midindex) {
		/* Find in right */
		return findMagicIndex(arr,midindex+1,rightindex);
	}
	else if (arr[midindex] > midindex) {
		/* Find in left */
		return findMagicIndex(arr,leftindex,midindex-1);
	}
	else {
		/* Mid itself */
		return midindex;
	}
}

int main(int argc, char *argv[]) {
	int arr[N] = {0};
	int index = 0;

	while (index < N) {
		arr[index] = -18 + index*2;
		index++;
	}

	index = 0;
	while (index < N) {
		printf("%d,",arr[index]);
		index++;
	}
	printf("\n");

	index = findMagicIndex(arr,0,N-1);
	if (index >= 0) {
		printf("Magic Index: %d, with array value: %d\n",index,arr[index]);
	}
	else {
		printf("Magic Index not found\n");
	}
	return 0;
}

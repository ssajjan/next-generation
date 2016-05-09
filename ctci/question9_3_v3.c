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

int findMagicIndexUnique(int *arr, int leftindex, int rightindex) {
	printf("LeftIndex: %d, RightIndex: %d\n",leftindex,rightindex);
	if ((arr[leftindex] > leftindex) || (arr[rightindex] < rightindex)) {
		return -1;
	}

	int midindex = (leftindex+rightindex)/2;
	printf("Mid index: %d\n",midindex);

	if (arr[midindex] < midindex) {
		/* Find in right */
		return findMagicIndexUnique(arr,midindex+1,rightindex);
	}
	else if (arr[midindex] > midindex) {
		/* Find in left */
		return findMagicIndexUnique(arr,leftindex,midindex-1);
	}
	else {
		/* Mid itself */
		return midindex;
	}
}

int findMagicIndex(int *arr, int leftindex, int rightindex) {
	printf("Leftindex: %d, Rightindex: %d\n",leftindex,rightindex);
	if ((rightindex < 0) || (leftindex > rightindex)){
		return -1;
	}
	
	int midindex = (leftindex + rightindex)/2;
	int midvalue = arr[midindex];
	printf("Leftindex: %d, Midindex: %d, Midvalue: %d, Rightindex: %d\n",leftindex,midindex,midvalue,rightindex);

	if (midindex == midvalue) {
		return midindex;
	}

	int index;
	/* Search Left */
	index = (midindex-1 < midvalue)?midindex-1:midvalue;
	index = findMagicIndex(arr,leftindex,index);
	if (index >= 0) {
		return index;
	}

	/* Search Right */
	index = (midindex+1 > midvalue)?midindex+1:midvalue;
	index = findMagicIndex(arr,index,rightindex);
	if (index > rightindex) {
		return -1;
	}
	else {
		return index;
	}
}

int main(int argc, char *argv[]) {
	int arr[N] = {0};
	int index = 0;

	while (index < N) {
		arr[index] = -10 + index*2;
		index++;
	}
	/*
	arr[6] = 9;
	arr[7] = 9;
	arr[8] = 9;
	arr[9] = 10;
	arr[10] = 11;
	arr[12] = 15;
	arr[13] = 15;
	arr[14] = 15;
	*/

	/*
	arr[10] = 11;
	arr[15] = 20;
	arr[16] = 20;
	arr[17] = 20;
	arr[18] = 20;
	arr[19] = 20;
	*/

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

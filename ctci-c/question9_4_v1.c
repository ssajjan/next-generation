/*
9.4
Write a method to return all subsets of a set.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define N 5

void printSet(int *set) {
	int index = 0;
	while (index < N) {
		printf("%d,",set[index]);
		index++;
	}
	printf("\n");
}

void printSubsetRec(int *set, int count) {
	if (count == 0) {
		printf("(),");
	}
	else if (count == 1) {
		printSubsetRec(set,count-1);
		printf("(%d),",set[count-1]);
	}
	else {
		printSubsetRec(set,count-1);
	}
}

void printSubset(int *set) {
	printSubsetRec(set,N);
}

int main(int argc, char *argv[]) {
	int set[N] = {1,2,3,45,67};
	//printSet(set);
	printSubset(set);
	return 0;
}

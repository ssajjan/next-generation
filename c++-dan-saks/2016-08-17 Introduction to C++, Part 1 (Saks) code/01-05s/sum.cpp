// sum.cpp - sum up the elements in an integer array

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <stdio.h>

int sum(int x[], int n) {
	int i;
	int s = 0;
	for (i = 0; i < n; ++i) {
		s += x[i];
	}
	return s;
}

#define DIM 8

int main() {
	int v[DIM] = { 91, 67, 23, -48, 712, 31, 1, -21 };
	int i;
	printf("the sum of:\n");
	for (i = 0; i < DIM; ++i) {
		printf("v[%d] = %d\n", i, v[i]);
	}
	printf("is %d\n", sum(v, DIM));
	return 0;
}


// swap.cpp - swap integers by value

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <stdio.h>

void swap(int v1, int v2) {
	int tmp = v1;
	v1 = v2;
	v2 = tmp;
}

int main() {
	int i = 1, j = 2;
	printf("Before swap(): i = %d, j = %d\n", i, j);
	swap(i, j);
	printf("After  swap(): i = %d, j = %d\n", i, j);
	return 0;
}


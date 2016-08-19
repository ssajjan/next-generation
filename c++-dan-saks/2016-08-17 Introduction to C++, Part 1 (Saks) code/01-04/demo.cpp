// demo.cpp - a printf demonstration

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <stdio.h>

int main() {
	int k = 31;
	double x = 19.2;
	printf("k = %d; x = %f\n", k, x);
	printf("k = (%4d); x = (%6.2f)\n", k, x);
	printf("k = (%-6d); x = (%-8.3f)\n", k, x);
	printf("k = (%x); x = (%e)\n", k, x);
	printf("k = (%8X); x = (%12E)\n", k, x);
	return 0;
}


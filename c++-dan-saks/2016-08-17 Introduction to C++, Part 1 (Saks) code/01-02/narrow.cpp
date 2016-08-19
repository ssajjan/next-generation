// narrow.cpp

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <stdio.h>

int main() {
	double d;
	float f;
	int i;
	unsigned u;
	d = 0.0;
	f = 0.0F;
	i = 0;
	u = 0U;
	i = f;      // discards fractional part of f
	f = i;      // might lose precision
	f = d;      // narrows double to float
	i = u;      // narrows unsigned int to signed int
	u = i;      // narrows signed int to unsigned int
	return 0;
}


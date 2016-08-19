// xrt.cpp - cross-reference table implementation

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <cassert>
#include <cstdio>
#include <cstring>

#include "xrt.h"

using namespace std;

void xrt::add(char *w, unsigned n) {
	size_t i;
	for (i = 0; i < xm; ++i) {
		if (strcmp(xa[i]->word, w) == 0) {
			break;
		}
	}
	if (i >= xm) {
		assert(i < MAX_ENTRIES);
		++xm;
		xa[i] = new entry;
		xa[i]->word = new char [strlen(w) + 1];
		strcpy(xa[i]->word, w);
		xa[i]->lines.init(n);
	} else {
		xa[i]->lines.add(n);
	}
}

void xrt::init() {
	xm = 0;
}

void xrt::put() {
	size_t i;
	sort();
	for (i = 0; i < xm; ++i) {
		printf("%15s:", xa[i]->word);
		xa[i]->lines.put();
		putchar('\n');
	}
}

void xrt::sort() {
	size_t i, j;
	if (xm == 0) {
		return;
	}
	for (i = 0; i < xm - 1; ++i) {
		for (j = i + 1; j < xm; ++j) {
			if (strcmp(xa[i]->word, xa[j]->word) > 0) {
				entry *temp = xa[i];
				xa[i] = xa[j];
				xa[j] = temp;
			}
		}
	}
}


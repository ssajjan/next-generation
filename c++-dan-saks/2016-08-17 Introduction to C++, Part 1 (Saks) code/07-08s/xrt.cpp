// xrt.cpp - cross-reference table implementation

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>

#include "xrt.h"

using namespace std;

entry::entry(char *w, unsigned n):
	lines (n) {
	word = new char [strlen(w) + 1];
	strcpy(word, w);
}

xrt::xrt() {
}

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
		xa[i] = new entry (w, n);
	} else {
		xa[i]->lines.add(n);
	}
}

void xrt::put() {
    sort();
	for (size_t i = 0; i < xm; ++i) {
		cout << setw(15) << xa[i]->word << ':';
		xa[i]->lines.put();
		cout << '\n';
	}
}

void xrt::sort() {
	if (xm == 0) {
		return;
	}
	for (size_t i = 0; i < xm - 1; ++i) {
		for (size_t j = i + 1; j < xm; ++j) {
			if (strcmp(xa[i]->word, xa[j]->word) > 0) {
				entry *temp = xa[i];
				xa[i] = xa[j];
				xa[j] = temp;
			}
		}
	}
}


// xrt.cpp - cross-reference table implementation

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>

#include "xrt.h"

using namespace std;

#ifndef NO_COUNTING
unsigned entry::counter = 0;
unsigned xrt::counter = 0;
#endif

entry::entry(char *w, unsigned n):
	lines (n) {
	word = new char [strlen(w) + 1];
	strcpy(word, w);
#ifndef NO_COUNTING
	cout << "entry()[" << ++counter << ']' << endl;
#endif
}

entry::~entry() {
#ifndef NO_COUNTING
	cout << "~entry()[" << --counter << ']' << endl;
#endif
	delete [] word;
}

xrt::xrt():
	xm (0) {
#ifndef NO_COUNTING
	cout << "xrt()[" << ++counter << ']' << endl;
#endif
}

xrt::~xrt() {
#ifndef NO_COUNTING
	cout << "~xrt()[" << --counter << ']' << endl;
#endif
	while (xm > 0) {
		delete xa[--xm];
	}
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


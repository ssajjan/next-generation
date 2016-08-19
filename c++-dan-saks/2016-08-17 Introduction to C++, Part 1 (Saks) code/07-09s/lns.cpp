// lns.cpp - line number set implementation

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <iomanip>
#include <iostream>

#include "lns.h"

using namespace std;

#ifndef NO_COUNTING
unsigned list_node::counter = 0;
unsigned lns::counter = 0;
#endif

list_node::list_node(unsigned n):
	number (n), next (nullptr) {
#ifndef NO_COUNTING
	cout << "list_node()[" << ++counter << ']' << endl;
#endif
}

lns::lns(unsigned n) {
	first = new list_node (n);
	last = first;
#ifndef NO_COUNTING
	cout << "lns()[" << ++counter << ']' << endl;
#endif
}

void lns::add(unsigned n) {
	if (last->number != n) {
		last->next = new list_node (n);
		last = last->next;
	}
}

void lns::put() {
	for (list_node *p = first; p != nullptr; p = p->next) {
		cout << ' ' << setw(7) << p->number;
	}
}


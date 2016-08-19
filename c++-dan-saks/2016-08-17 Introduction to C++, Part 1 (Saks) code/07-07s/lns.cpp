// lns.cpp - line number set implementation

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <iomanip>
#include <iostream>

#include "lns.h"

list_node::list_node(unsigned n):
	number (n), next (nullptr) {
}

lns::lns(unsigned n) {
	first = new list_node (n);
	last = first;
}

void lns::add(unsigned n) {
	if (last->number != n) {
		last->next = new list_node (n);
		last = last->next;
	}
}

void lns::put() {
	using namespace std;
	for (list_node *p = first; p != nullptr; p = p->next) {
		cout << ' ' << setw(7) << p->number;
	}
}


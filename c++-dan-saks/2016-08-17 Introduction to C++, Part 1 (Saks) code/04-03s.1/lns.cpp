// lns.cpp - line number set implementation

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <stdio.h>

#include "lns.h"

void lns::add(unsigned n) {
	last->next = new list_node;
	last = last->next;
	last->number = n;
	last->next = NULL;
}

void lns::init(unsigned n) {
	first = new list_node;
	last = first;
	last->number = n;
	last->next = NULL;
}

unsigned lns::most_recent() {
	return last->number;
}

void lns::put() {
	list_node *p;
	for (p = first; p != NULL; p = p->next) {
		printf(" %7d", p->number);
	}
}


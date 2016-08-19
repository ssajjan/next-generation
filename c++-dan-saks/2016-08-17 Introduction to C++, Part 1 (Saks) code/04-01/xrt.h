// xrt.h - cross-reference table interface

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <stddef.h>     // for size_t

struct list_node {
	unsigned number;
	list_node *next;
};

struct entry {
	char *word;
	list_node *first, *last;
};

size_t const MAX_ENTRIES = 1024;

class xrt {
public:
	void add(char *w, unsigned n);
	void init();
	void put();
	void sort();
private:
	entry *xa[MAX_ENTRIES];
	size_t xm;
};


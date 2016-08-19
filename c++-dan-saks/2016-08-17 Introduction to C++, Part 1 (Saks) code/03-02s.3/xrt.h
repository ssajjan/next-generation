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

struct xrt {
	entry *xa[MAX_ENTRIES];
	size_t xm;
};

void xrt_add(xrt *t, char *w, unsigned n);
void xrt_init(xrt *t);
void xrt_put(xrt *t);
void xrt_sort(xrt *t);


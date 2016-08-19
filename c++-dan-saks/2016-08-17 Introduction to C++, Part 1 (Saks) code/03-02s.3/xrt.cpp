// xrt.cpp - cross-reference table implementation

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "xrt.h"

void xrt_add(xrt *t, char *w, unsigned n) {
	size_t i;
	for (i = 0; i < t->xm; ++i) {
		if (strcmp(t->xa[i]->word, w) == 0) {
			break;
		}
	}
	if (i >= t->xm) {
		assert(i < MAX_ENTRIES);
		++t->xm;
		t->xa[i] = new entry;
		t->xa[i]->word = new char [strlen(w) + 1];
		strcpy(t->xa[i]->word, w);
		t->xa[i]->first = new list_node;
		t->xa[i]->last = t->xa[i]->first;
		t->xa[i]->last->number = n;
		t->xa[i]->last->next = NULL;
	} else if (t->xa[i]->last->number != n) {
		t->xa[i]->last->next = new list_node;
		t->xa[i]->last = t->xa[i]->last->next;
		t->xa[i]->last->number = n;
		t->xa[i]->last->next = NULL;
	}
}

void xrt_init(xrt *t) {
	t->xm = 0;
}

void xrt_put(xrt *t) {
	size_t i;
	list_node *p;
	for (i = 0; i < t->xm; ++i) {
		printf("%15s:", t->xa[i]->word);
		for (p = t->xa[i]->first; p != NULL; p = p->next) {
			printf(" %7d", p->number);
		}
		putchar('\n');
	}
}

void xrt_sort(xrt *t) {
	size_t i, j;
	if (t->xm == 0) {
		return;
	}
	for (i = 0; i < t->xm - 1; ++i) {
		for (j = i + 1; j < t->xm; ++j) {
			if (strcmp(t->xa[i]->word, t->xa[j]->word) > 0) {
				entry *temp = t->xa[i];
				t->xa[i] = t->xa[j];
				t->xa[j] = temp;
			}
		}
	}
}


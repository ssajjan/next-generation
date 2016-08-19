// xr.cpp - a cross-reference generator

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// input processing components

bool get_token(char *t, size_t n);

// cross-reference table components

struct list_node {
	unsigned number;
	list_node *next;
};

struct entry {
	char *word;
	list_node *first, *last;
};

size_t const MAX_ENTRIES = 1024;
entry *xa[MAX_ENTRIES];
size_t xm = 0;

void add_array(entry *a[], size_t *m, char *w, unsigned n);
void put_array(entry *a[], size_t m);
void sort_array(entry *a[], size_t m);

// the main function

int main() {
	size_t const MAX_TOKEN = 64;
	char token[MAX_TOKEN];
	unsigned ln = 1;
	while (get_token(token, MAX_TOKEN)) {
		if (isalpha(token[0]) || token[0] == '_') {
			add_array(xa, &xm, token, ln);
		} else { // if (token[0] == '\n')
			++ln;
		}
	}
	sort_array(xa, xm);
	put_array(xa, xm);
	return 0;
}

// more input processing components

bool get_token(char *t, size_t n) {
	int c;
	if (n < 2) {
		return false;
	}
	while ((c = getchar()) != EOF) {
		if (isalpha(c) || c == '_' || c == '\n') {
			break;
		}
	}
	if (c == EOF) {
		return false;
	}
	*t++ = static_cast<char>(c);
	--n;
	if (c != '\n') {
		while ((c = getchar()) != EOF) {
			if (!isalnum(c) && c != '_') {
				ungetc(c, stdin);
				break;
			} else if (n > 1) {
				*t++ = static_cast<char>(c);
				--n;
			}
		}
	}
	*t = '\0';
	return true;
}

// more cross-reference table components

void add_array(entry *a[], size_t *m, char *w, unsigned n) {
	size_t i;
	for (i = 0; i < *m; ++i) {
		if (strcmp(a[i]->word, w) == 0) {
			break;
		}
	}
	if (i >= *m) {
		assert(i < MAX_ENTRIES);
		++*m;
		a[i] = new entry;
		a[i]->word = new char [strlen(w) + 1];
		strcpy(a[i]->word, w);
		a[i]->first = new list_node;
		a[i]->last = a[i]->first;
		a[i]->last->number = n;
		a[i]->last->next = NULL;
	} else if (a[i]->last->number != n) {
		a[i]->last->next = new list_node;
		a[i]->last = a[i]->last->next;
		a[i]->last->number = n;
		a[i]->last->next = NULL;
	}
}

void put_array(entry *a[], size_t m) {
	size_t i;
	list_node *p;
	for (i = 0; i < m; ++i) {
		printf("%15s:", a[i]->word);
		for (p = a[i]->first; p != NULL; p = p->next) {
			printf(" %7d", p->number);
		}
		putchar('\n');
	}
}

void sort_array(entry *a[], size_t m) {
	size_t i, j;
	if (m == 0) {
		return;
	}
	for (i = 0; i < m - 1; ++i) {
		for (j = i + 1; j < m; ++j) {
			if (strcmp(a[i]->word, a[j]->word) > 0) {
				entry *temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}


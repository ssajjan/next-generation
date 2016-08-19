// xr.cpp - a cross-reference generator

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// input processing components

int get_token(char *t, size_t n);

// cross-reference table components

struct list_node {
	unsigned number;
	struct list_node *next;
};

struct entry {
	char *word;
	struct list_node *first, *last;
};

enum { MAX_ENTRIES = 1024 };
struct entry *xa[MAX_ENTRIES];
size_t xm = 0;

void add_array(struct entry *a[], size_t *m, char *w, unsigned n);
void put_array(struct entry *a[], size_t m);
void sort_array(struct entry *a[], size_t m);

// the main function

int main() {
	enum { MAX_TOKEN = 64 };
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

int get_token(char *t, size_t n) {
	int c;
	if (n < 2) {
		return 0;
	}
	while ((c = getchar()) != EOF) {
		if (isalpha(c) || c == '_' || c == '\n') {
			break;
		}
	}
	if (c == EOF) {
		return 0;
	}
	*t++ = (char)c;
	--n;
	if (c != '\n') {
		while ((c = getchar()) != EOF) {
			if (!isalnum(c) && c != '_') {
				ungetc(c, stdin);
				break;
			} else if (n > 1) {
				*t++ = (char)c;
				--n;
			}
		}
	}
	*t = '\0';
	return 1;
}

// more cross-reference table components

void add_array(struct entry *a[], size_t *m, char *w, unsigned n) {
	size_t i;
	for (i = 0; i < *m; ++i) {
		if (strcmp(a[i]->word, w) == 0) {
			break;
		}
	}
	if (i >= *m) {
		assert(i < MAX_ENTRIES);
		++*m;
		a[i] = (struct entry *)malloc(sizeof(struct entry));
		a[i]->word = (char *)malloc((strlen(w) + 1) * sizeof(char));
		strcpy(a[i]->word, w);
		a[i]->first = (struct list_node *)malloc(sizeof(struct list_node));
		a[i]->last = a[i]->first;
		a[i]->last->number = n;
		a[i]->last->next = NULL;
	} else if (a[i]->last->number != n) {
		a[i]->last->next = (struct list_node *)malloc(sizeof(struct list_node));
		a[i]->last = a[i]->last->next;
		a[i]->last->number = n;
		a[i]->last->next = NULL;
	}
}

void put_array(struct entry *a[], size_t m) {
	size_t i;
	struct list_node *p;
	for (i = 0; i < m; ++i) {
		printf("%15s:", a[i]->word);
		for (p = a[i]->first; p != NULL; p = p->next) {
			printf(" %7d", p->number);
		}
		putchar('\n');
	}
}

void sort_array(struct entry *a[], size_t m) {
	size_t i, j;
	if (m == 0) {
		return;
	}
	for (i = 0; i < m - 1; ++i) {
		for (j = i + 1; j < m; ++j) {
			if (strcmp(a[i]->word, a[j]->word) > 0) {
				struct entry *temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}


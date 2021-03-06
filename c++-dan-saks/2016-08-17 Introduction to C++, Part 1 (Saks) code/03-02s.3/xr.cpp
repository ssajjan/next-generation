// xr.cpp - a cross-reference generator

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

// #include <assert.h>
#include <ctype.h>
#include <stdio.h>
// #include <string.h>

#include "xrt.h"

// input processing components

bool get_token(char *t, size_t n);

// the main function

int main() {
	size_t const MAX_TOKEN = 64;
	char token[MAX_TOKEN];
	unsigned ln = 1;
	xrt lower, upper;
	xrt_init(&lower);
	xrt_init(&upper);
	while (get_token(token, MAX_TOKEN)) {
		if (islower(token[0]) || token[0] == '_') {
			xrt_add(&lower, token, ln);
		} else if (isupper(token[0])) {
			xrt_add(&upper, token, ln);
		} else { // if (token[0] == '\n')
			++ln;
		}
	}
	xrt_sort(&lower);
	xrt_sort(&upper);
	xrt_put(&lower);
	xrt_put(&upper);
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


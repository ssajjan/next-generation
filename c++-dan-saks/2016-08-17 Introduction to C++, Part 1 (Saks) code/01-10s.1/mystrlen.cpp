// mystrlen.cpp - a function similar to strlen

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <stdio.h>

int mystrlen(char *s) {
	char *p = s;
	while (*p != '\0') {
		++p;
	}
	return p - s;
}

void test(char s[]) {
	printf("the length of \"%s\" is %d\n", s, mystrlen(s));
}

int main() {
	test("hello, world");
	test("aloha, Hawaii");
	test("guten tag, Deutschland");
	return 0;
}


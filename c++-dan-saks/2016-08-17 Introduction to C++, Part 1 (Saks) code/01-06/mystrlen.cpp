// mystrlen.cpp

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <stdio.h>

int mystrlen(char s[]) {
	int i = 0;
	while (s[i] != '\0') {
		++i;
	}
	return i;
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


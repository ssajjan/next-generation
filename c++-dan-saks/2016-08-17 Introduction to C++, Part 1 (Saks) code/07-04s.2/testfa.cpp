// testfa.cpp - test float_array

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <cstddef>
#include <iostream>

#include "fa.h"

using namespace std;

void display(char *s, float_array &fa) {
	cout << s << " =";
	for (size_t i = 0; i < fa.length(); ++i) {
		cout << ' ' << fa.get(i);
	}
	cout << endl;
}

int main() {
	size_t length;
	cout << "length? ";
	cin >> length;
	float_array fa (length), fb;
	display("fa", fa);
	display("fb", fb);
	for (size_t i = 0; i < fa.length(); ++i) {
		fa.set(i, static_cast<float>(i));
	}
	display("fa", fa);
	float_array fc (fa);
	display("fc", fc);
	for (size_t i = 0; i < fc.length(); ++i) {
		fc.set(i, static_cast<float>(i * i));
	}
	display("fc", fc);
	fb.copy(fc);
	display("fb", fb);
	fa.copy(fa);
	display("fa", fa);
	float_array fd;
	display("fd", fd);
	fd.copy(fa);
	display("fd", fd);
	display("fa", fa);
	return 0;
}


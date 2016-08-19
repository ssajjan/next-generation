// testfa.cpp - test float_array

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <cstddef>
#include <iostream>

#include "fa.h"

using namespace std;

void display(char *s, float_array &fa) {
	size_t i;
	cout << s << " =";
	for (i = 0; i < fa.length(); ++i) {
		cout << ' ' << fa.get(i);
	}
	cout << endl;
}

int main() {
	size_t length;
	cout << "length? ";
	cin >> length;
	float_array fa;
	fa.create(length);
    float_array fb;
	fb.create(0);
	display("fa", fa);
	display("fb", fb);
	size_t i;
	for (i = 0; i < fa.length(); ++i) {
		fa.set(i, static_cast<float>(i));
	}
	display("fa", fa);
	float_array fc;
	fc.create(fa.length());
	for (i = 0; i < fc.length(); ++i) {
		fc.set(i, static_cast<float>(i * i));
	}
	display("fc", fc);
	fa.destroy();
	fb.destroy();
	fc.destroy();
	return 0;
}


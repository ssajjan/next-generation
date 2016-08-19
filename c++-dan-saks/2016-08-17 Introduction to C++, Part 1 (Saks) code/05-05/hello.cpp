// hello.cpp

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <iostream>

using namespace std;

int main() {
	char name[20];
	cout << "Who are you? ";
	cin >> name;
	cout << "Hello, " << name << '\n';
	return 0;
}


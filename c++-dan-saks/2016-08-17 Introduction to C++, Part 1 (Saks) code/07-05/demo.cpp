// demo.cpp

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <iostream>

using namespace std;

class T {
public:
	T(int i);
	int value();
private:
	int t;
};

T::T(int i) {
	t = i;
}

int T::value() {
	return t;
}

int main() {
	T a[] = { 1, 4, 9 };
	for (std::size_t i = 0; i < 3; ++i) {
		cout << a[i].value() << endl;
	}
#if 0 // change this to 1 for C++11
	T *p = new T [4] { 16, 25, 36, 49 };
	for (std::size_t i = 0; i < 4; ++i) {
		cout << p[i].value() << endl;
	}
#endif
	return 0;
}


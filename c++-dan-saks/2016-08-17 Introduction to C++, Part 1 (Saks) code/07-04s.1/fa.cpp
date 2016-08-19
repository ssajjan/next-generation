// fa.cpp - float_array implementation

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include <iostream>

#include "fa.h"

using namespace std;

float_array::float_array() {
	cout << "float_array() called for the object at "
		<< this << endl;
	stored_length = 0;
	actual_array = nullptr;
}

float_array::float_array(size_t n) {
	cout << "float_array(size_t) called for the object at "
		<< this << endl;
	stored_length = n;
	actual_array = new float [n];
}

float_array::float_array(float_array &fa) {
	cout << "float_array(float_array &) called for the object at "
		<< this << endl;
	stored_length = fa.stored_length;
	actual_array = new float [stored_length];
	for (size_t i = 0; i < stored_length; ++i) {
		actual_array[i] = fa.actual_array[i];
	}
}

float_array::~float_array() {
	cout << "~float_array() called for the object at "
		<< this << endl;
	delete [] actual_array;
}

void float_array::copy(float_array &fa) {
	if (this == &fa) {
		return;
	}
	if (stored_length != fa.stored_length) {
		delete [] actual_array;
		stored_length = fa.stored_length;
		actual_array = new float [stored_length];
	}
	for (size_t i = 0; i < stored_length; ++i) {
		actual_array[i] = fa.actual_array[i];
	}
}

float float_array::get(size_t i) {
	return actual_array[i];
}

void float_array::set(size_t i, float f) {
	actual_array[i] = f;
}

size_t float_array::length() {
	return stored_length;
}


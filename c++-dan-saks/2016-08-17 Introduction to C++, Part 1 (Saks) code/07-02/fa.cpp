// fa.cpp - float_array implementation

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include "fa.h"

using namespace std;

float_array::float_array(size_t n) {
	stored_length = n;
	actual_array = new float [n];
}

float_array::~float_array() {
	delete [] actual_array;
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


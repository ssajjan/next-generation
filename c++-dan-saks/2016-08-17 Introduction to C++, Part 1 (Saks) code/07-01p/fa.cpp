// fa.cpp - float_array implementation

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#include "fa.h"

using namespace std;

void float_array::create(size_t n) {
	stored_length = n;
	actual_array = new float [n];
}

void float_array::destroy() {
	// fill this in
}

float float_array::get(size_t i) {
	// fill this in
}

void float_array::set(size_t i, float f) {
	// fill this in
}

size_t float_array::length() {
	// fill this in
}


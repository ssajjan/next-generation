// fa.h - float_array interface

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#ifndef FA_H_INCLUDED
#define FA_H_INCLUDED

#include <cstddef>

class float_array {
public:
	void create(std::size_t n);
	void destroy();
	float get(std::size_t i);
	void set(std::size_t i, float f);
	std::size_t length();
private:
	std::size_t stored_length;
	float *actual_array;
};

#endif


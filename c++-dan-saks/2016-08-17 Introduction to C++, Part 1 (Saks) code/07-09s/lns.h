// lns.h - line number set interface

// Copyright (c) 2016 by Dan Saks.

// See _readme.txt.

#ifndef LNS_H_INCLUDED
#define LNS_H_INCLUDED

struct list_node {
	list_node(unsigned n);
	unsigned number;
	list_node *next;
#ifndef NO_COUNTING
	static unsigned counter;
#endif
};

class lns {
public:
	lns(unsigned n);
	void add(unsigned n);
	void put();
private:
	list_node *first, *last;
#ifndef NO_COUNTING
	static unsigned counter;
#endif
};

#endif


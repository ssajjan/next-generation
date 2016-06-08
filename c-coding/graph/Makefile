# unix Makefile

PROGS = graph

#assertion binary_search  bubble-sort_binary-search  gets  malloc  printf  strcpy \
	assertion-improved  bit  example  is_big_endia  linkedlistexample  namechange  replace-string  struct-size \
	atoi bitwise  _exit  linkedlist-sajjan  packaging


ifeq ($(TERM),cygwin)
    EXES = ${PROGS:=.exe}
else
    EXES = $(PROGS)
endif

INCLUDES = -I./

CFLAGS = -Wall -O2 -std=c99 -Wimplicit-function-declaration -Wpointer-to-int-cast -Wunused-result
CFLAGS += $(INCLUDES)
all: $(PROGS)

clean:
	rm -f $(EXES)

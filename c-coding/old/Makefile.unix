# unix Makefile

PROGS = bin ext has ins qui quilist\
	qsort rbt skl shl btr rbtr

ifeq ($(TERM),cygwin)
    EXES = ${PROGS:=.exe}
else
    EXES = $(PROGS)
endif

OBJS = rbtr.o rbtrmain.o

CFLAGS = -Wall -O2

all: $(PROGS)

rbtr: $(OBJS)

clean:
	rm -f $(EXES) $(OBJS)

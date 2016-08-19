# make hello using TDM-GCC
# compile as C++ for Windows
# Copyright (c) 2016 by Dan Saks
# See _readme.txt

SRC = .c    # source
OBJ = .o    # object
EXE = .exe  # executable
MAP = .m    # link map
ASM = .s    # assembler

CC = gcc
AFLAGS = -c -O3 -o $@ -std=c++11 -Wall -x c++
CFLAGS = -g $(AFLAGS)

LL = $(CC)
LFLAGS = -g -Xlinker -M -Xlinker -Map -Xlinker $*$(MAP) -o $@

%$(EXE): %$(OBJ)
	$(LL) $^ $(LFLAGS)

%$(OBJ): %$(SRC)
	$(CC) $(CFLAGS) $*$(SRC)

%$(ASM): %$(SRC)
	$(CC) $(AFLAGS) -S $*$(SRC)

hello$(EXE):

hello$(OBJ):

clean:
	cmd /c del *.bak *$(EXE) *$(OBJ) *$(MAP) *$(ASM)


# make greet using TDM-GCC
# compile as C++ for Windows
# Copyright (c) 2016 by Dan Saks
# See _readme.txt

SRC = .cpp  # source
OBJ = .o    # object
EXE = .exe  # executable
MAP = .m    # link map
ASM = .s    # assembler

CC = g++
AFLAGS = -c -O3 -o $@ -std=c++11 -Wall
CFLAGS = -g $(AFLAGS)

LL = $(CC)
LFLAGS = -g -Xlinker -M -Xlinker -Map -Xlinker $*$(MAP) -o $@

%$(EXE): %$(OBJ)
	$(LL) $^ $(LFLAGS)

%$(OBJ): %$(SRC)
	$(CC) $(CFLAGS) $*$(SRC)

%$(ASM): %$(SRC)
	$(CC) $(AFLAGS) -S $*$(SRC)

greet$(EXE): greet$(OBJ) hello$(OBJ)

greet$(OBJ): hello.h

hello$(OBJ): hello.h

greet$(ASM): hello.h

hello$(ASM): hello.h

clean:
	cmd /c del *.bak *$(EXE) *$(OBJ) *$(MAP) *$(ASM)


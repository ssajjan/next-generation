# make xr using TDM-GCC
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

xr$(EXE): xr$(OBJ) xrt$(OBJ)

xr$(OBJ): xrt.h

xrt$(OBJ): xrt.h

xr$(ASM): xrt.h

xrt$(ASM): xrt.h

clean:
	cmd /c del *.bak *$(EXE) *$(OBJ) *$(MAP) *$(ASM)


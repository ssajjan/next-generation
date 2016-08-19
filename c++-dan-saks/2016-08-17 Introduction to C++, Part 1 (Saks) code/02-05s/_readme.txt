xr - a cross-reference generator

Copyright (c) 2016 by Dan Saks. Do not distribute any of the files in this
folder without the file notice.txt.

This version introduce replaces malloc calls with new-expressions. It
also:

- redefines the symbols MAX_ENTRIES and MAX_TOKEN as const objects instead
  of as enumeration constants,

- remove the keyword struct everywhere except as the leading keyword in a
  structure definition, and

- replaces each remaining old-style cast with an appropriate new-style
  cast.

The program compiles only as C++, not as C.


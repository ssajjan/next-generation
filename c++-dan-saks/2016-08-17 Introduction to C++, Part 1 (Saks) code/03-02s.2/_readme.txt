xr - a cross-reference generator

Copyright (c) 2016 by Dan Saks. Do not distribute any of the files in this
folder without the file notice.txt.

This version introduces the xrt structure as an abstract type. It declares
lower and upper as local xrt objects with automatic storage. It
initializes each xrt object by explicitly initializing its xm member to 0.
It works, but it compromises the xrt abstraction by exposing the xm
member.

This is not a good solution.


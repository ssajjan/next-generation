xr - a cross-reference generator

Copyright (c) 2016 by Dan Saks. Do not distribute any of the files in this
folder without the file notice.txt.

This version introduces the xrt structure as an abstract type. It fails to
explicitly initialize lower and upper. However, it works because it
declares lower and upper as global objects. Global objects have static
storage and are initialized to 0 by default.

This is not a good solution.


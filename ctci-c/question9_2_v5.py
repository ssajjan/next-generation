#!/usr/bin/python

"""
9.2
"""
points = {}

def totalpaths(x,y):
    if (x==0 and y==0):
        return 0
    elif (x == 0):
        return 1
    elif (y == 0):
        return 1
    elif (points.has_key((x,y))):
        return points[(x,y)]
    else:
            points[(x,y)] = totalpaths(x-1,y) + totalpaths(x,y-1)
            return points[(x,y)]

# main()
#single = int(raw_input)
x,y = map(int,raw_input().split())
print("Total paths from (0,0) to (" + str(x) + "," + str(y) + "): " + str(totalpaths(x,y)))

#!/usr/bin/python

"""
9.2
"""
points = {}

def isFree(x,y):
    if ((x!=4 or y!=4) and (x!=5 or y!=5) and (x!=6 or y!=6) and (x!=9 or y!=8) and (x!=8 or y!=9)):
        return True
    else:
        return False

def totalpaths(x,y):
    #print(x,y)
    if (x==0 and y==0):
        return 0
    elif (x == 0):
        return 1
    elif (y == 0):
        return 1
    elif (points.has_key((x,y))):
        return points[(x,y)]
    else:
	if (isFree(x-1,y) and isFree(x,y-1)):
            points[(x,y)] = totalpaths(x-1,y) + totalpaths(x,y-1)
            return points[(x,y)]
	elif (isFree(x-1,y)):
            points[(x,y)] = totalpaths(x-1,y)
            return points[(x,y)]
	elif (isFree(x,y-1)):
            points[(x,y)] = totalpaths(x,y-1)
            return points[(x,y)]
	else:
            points[(x,y)] = 0
            return points[(x,y)]

# main()
#single = int(raw_input)
x,y = map(int,raw_input().split())
print("Total paths from (0,0) to (" + str(x) + "," + str(y) + "): " + str(totalpaths(x,y)))

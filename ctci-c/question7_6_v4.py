#!/usr/bin/python

"""
7.6
Given a two-dimensional graph with points on it, find a line which passes the most
number of points
"""

def generate_line(p1, p2):
    if (p2[0] != p1[0]):
        m = (p2[1] - p1[1])/(p2[0] - p1[0])
        c = p2[1] - m * p2[0]
        return (m,c)
    else:
	b = p2[0]
        return ('x',b);

def best_line(points):
    lines = {}
    best_line = None
    best_line_count = 0
     
    for i in range(len(points)):
        for j in range(i+1, len(points)):
            line = generate_line(points[i], points[j])
            if (lines.has_key(line)):
                lines[line] = lines[line] + 1
            else:
                lines[line] = 1
 
            if (lines[line] > best_line_count):
                best_line = line
		best_line_count = lines[line]
 
    print lines
    return best_line
 

# main()
points = []
point = [1,1]
points.append(point)

point = [2,3]
points.append(point)

point = [-4,8]
points.append(point)

point = [2,5]
points.append(point)

point = [5,5]
points.append(point)

line = best_line(points)
print("Best Line is: " + str(line))

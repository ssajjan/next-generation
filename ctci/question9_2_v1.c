/*
9.2
Imagine a robot sitting on the upper left comer of an X by Ygrid. The robot can only
move in two directions: right and down. How many possible paths are there for the
robot to go from (0, 0) to (X, Y) ?
FOLLOW UP
Imagine certain spots are "off limits," such that the robot cannot step on them.
Design an algorithm to find a path for the robot from the top left to the bottom right.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int totalpaths(int x, int y) {
	int count = 0;
	if (x == 0 && y == 0) {
		return 0;
	}
	else if (x == 0) {
		return y;
	}
	else if (y == 0) {
		return x;
	}
	else {
		count += totalpaths(x-1,y) + totalpaths(x,y-1);
		return count;
	}
}

int main(int argc, char *argv[]) {
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);

	printf("Total number of ways from (0,0) to (%d,%d): %d\n",x,y,totalpaths(x,y));
	return 0;
}

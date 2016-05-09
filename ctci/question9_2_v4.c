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

bool isFree(int x, int y) {
	if ((x!=4 || y!= 4) && (x!=5 || y!=5) && (x!=7 || y!=8) && (x!=8 || y!=7)) {
		return true;
	}
	else {
		return false;
	}
}

long unsigned int totalpaths(int x, int y, long unsigned int *map) {
	if (x == 0 && y == 0) {
		return 0;
	}
	else if (x == 0) {
		return 1;
	}
	else if (y == 0) {
		return 1;
	}
	else if (*(map+x*21+y) > 0) {
		return *(map+x*21+y);
	}
	else {
		if (isFree(x-1,y) && isFree(x,y-1)) {
			*(map+x*21+y) = totalpaths(x-1,y,map) + totalpaths(x,y-1,map);
			return *(map+x*21+y);
		}
		else if (isFree(x-1,y)) {
			*(map+x*21+y) = totalpaths(x-1,y,map);
			return *(map+x*21+y);
		}
		else if (isFree(x,y-1)) {
			*(map+x*21+y) = totalpaths(x,y-1,map);
			return *(map+x*21+y);
		}
		else {
			*(map+x*21+y) = 0;
			return *(map+x*21+y);
		}
	}
}

int main(int argc, char *argv[]) {
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	
	long unsigned int map[20+1][20+1] = {0};
	/*
	for (int xindex = 0; xindex < 21; xindex++) {
		for (int yindex = 0; yindex < 21; yindex++) {
			printf("%lu,",map[xindex][yindex]);
		}
		printf("\n");
	}
	printf("\n");
	*/

	printf("Total number of ways from (0,0) to (%d,%d): %lu\n",x,y,totalpaths(x,y,&map[0][0]));

	/*
	for (int xindex = 0; xindex < 21; xindex++) {
		for (int yindex = 0; yindex < 21; yindex++) {
			printf("%lu,",map[xindex][yindex]);
		}
		printf("\n");
	}
	printf("\n");
	*/

	/*
	printf("%p\n",&map[0]);
	printf("%p\n",&map[1][5]);
	printf("%p\n",&map[1][5]);
	printf("%d\n",map[1][5]);
	printf("%p\n",map+1*21+5);
	printf("%p\n",*(map+1*21+5));
	printf("%d\n",*(*(map+1)+5));
	printf("%p\n",(int *)map+1*21+5);
	printf("%d\n",*((int *)map+1*21+5));
	*/

	return 0;
}

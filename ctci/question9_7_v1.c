/*
9.7
Implement the "paint fill" function that one might see on many image editing
programs. That is, given a screen (represented by a two-dimensional array of colors),
a point, and a new color, fill in the surrounding area until the color changes from the
original color.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_LEN 10

enum color {
	Black,
	Grey,
	White
};

void initScreen(enum color *screen, enum color fillcolor) {
//void initScreen(enum color screen[][MAX_LEN], enum color fillcolor) {
	for (int x = 0; x < MAX_LEN; x++) {
		for (int y = 0; y < MAX_LEN; y++) {
			*(screen+y*MAX_LEN+x) = fillcolor;
			//screen[x][y] = fillcolor;
		}
	}
}

void printScreen(enum color *screen) {
//void printScreen(enum color screen[][MAX_LEN]) {
	printf("\n\t");
	for (int x = 0; x < MAX_LEN; x++) {
		for (int y = 0; y < MAX_LEN; y++) {
			printf("%d  ",*(screen+y*MAX_LEN+x));
			//printf("%d  ",screen[x][y]);
		}
		printf("\n\t");
	}
}

bool fillColor(enum color *screen, int x, int y, enum color oldcolor, enum color newcolor) {
//bool fillColor(enum color screen[][MAX_LEN], int x, int y, enum color oldcolor, enum color newcolor) {
	if (x < 0 || x >= MAX_LEN || y < 0 || y >= MAX_LEN) {
		return false;
	}

	if (*(screen+y*MAX_LEN+x) == oldcolor) {
		*(screen+y*MAX_LEN+x) = newcolor;
	//if (screen[x][y] == oldcolor) {
	//	screen[x][y] = newcolor;
		fillColor(screen, x-1, y-1, oldcolor, newcolor);
		fillColor(screen, x  , y-1, oldcolor, newcolor);
		fillColor(screen, x+1, y-1, oldcolor, newcolor);
		fillColor(screen, x+1, y  , oldcolor, newcolor);
		fillColor(screen, x+1, y+1, oldcolor, newcolor);
		fillColor(screen, x  , y+1, oldcolor, newcolor);
		fillColor(screen, x-1, y+1, oldcolor, newcolor);
		fillColor(screen, x-1, y  , oldcolor, newcolor);
	}

	return true;
}

int main(int argc, char *argv[]) {
	enum color screen[MAX_LEN][MAX_LEN];
        int x = 2, y = 2;
        enum color newcolor, oldcolor, defcolor;

        defcolor = Black;
        oldcolor = Grey;
        newcolor = White;

	initScreen((enum color *)screen,defcolor);
	//initScreen(screen,defcolor);

	screen[0][0] = oldcolor;
	screen[1][1] = oldcolor;
	screen[2][1] = oldcolor;
	screen[3][3] = oldcolor;
	screen[4][4] = oldcolor;
	screen[5][5] = oldcolor;
	screen[6][6] = oldcolor;
	screen[7][7] = oldcolor;
	screen[8][8] = oldcolor;
	screen[9][9] = oldcolor;

	printScreen((enum color *)screen);
	//printScreen(screen);

	fillColor((enum color *)screen,x,y,oldcolor,newcolor);
	//fillColor(screen,x,y,oldcolor,newcolor);

	printScreen((enum color *)screen);
	//printScreen(screen);

	fillColor((enum color *)screen,x-1,y,defcolor,oldcolor);
	//fillColor(screen,x-1,y,defcolor,oldcolor);

	printScreen((enum color *)screen);
	//printScreen(screen);

	return 0;
}

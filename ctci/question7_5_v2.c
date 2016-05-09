/*
7.5
Given two squares on a two-dimensional plane, find a line that would cut these two
squares in half. Assume that the top and the bottom sides of the square run parallel
to the x-axis.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define EPSILON 0.000001

struct Point {
	double x;
	double y;
};

struct Line {
	double slope;
	double yintercept;
};

struct Square {
	double xleft;
	double xright;
	double ytop;
	double ybottom;
};

void setPoint(struct Point *point, double xval, double yval) {
	point->x = xval;
	point->y = yval;
}

void setLine(struct Line *line, double m, double c) {
	line->slope = m;
	line->yintercept = c;
}

void setSquare(struct Square *sq, double xl, double xr, double yt, double yb) {
	sq->xleft   = xl;
	sq->ytop    = yt;
	sq->xright  = xr;
	sq->ybottom = yb;
}

struct Point getSquareCentre(struct Square sq) {
	struct Point centre;
	centre.x = (sq.xleft + sq.xright)/2;
	centre.y = (sq.ytop + sq.ybottom)/2;
	return centre;
}

double getSlope(struct Point p1, struct Point p2) {
	if (fabs(p2.x - p1.x) < EPSILON) {
		if (fabs(p2.y- p1.y) < EPSILON) {
			printf("Slope: Indeterminate since p1 and p2 are same points\n");
		}
		else {
			printf("Slope: Infinite(Parallel to y-axis)\n");
		}
		return 0;
	}
	else {
		return ((p2.y - p1.y)/(p2.x - p1.x));
	}
}

double getYintercept(double m, struct Point sqc1) {
	return (sqc1.y - m*sqc1.x);
}

bool intersect(struct Line line1, struct Line line2) {
	return ((fabs(line1.slope - line2.slope) > EPSILON) || (fabs(line1.yintercept - line2.yintercept) < EPSILON));
}

struct Point getIntersectPoint(struct Line line1, struct Line line2) {
	bool intrsct = false;
	intrsct = intersect(line1,line2);

	printf("Line1 and Line2 intersect: %s\n",intrsct==1?"True":"False");

	struct Point p;
	if (intrsct == 1) {
		p.x = ((line2.yintercept-line1.yintercept)/(line1.slope-line2.slope));
		p.y = (line1.slope)*(p.x)+line1.yintercept;
		return p;
	}
	else {
		return p;
	}
}

int main(int argc, char *argv[]) {
	/*
	printf("Argument count: %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("Argument vector values:%s at %p memory\n", argv[i], argv[i]);
		for (char *j=argv[i]; *j!='\0'; j++) {
			printf("Another way to print argument vector values: "
                               "%c at %p memory\n", *j, j);
		}
	}
	*/

	struct Line line1;
	double m,c;

	m = -1.00;
	c = 6.00;
	setLine(&line1,m,c);
	//printf("Line1 has slope: %f and y-intercept: %f\n",line1.slope,line1.yintercept);

	struct Line line2;
	m = 1.00;
	c = 6.00;
	setLine(&line2,m,c);
	//printf("Line2 has slope: %f and y-intercept: %f\n",line2.slope,line2.yintercept);

	struct Point p1;
	double xval,yval;

	xval = 2;
	yval = 1;
	setPoint(&p1,xval,yval);
	//printf("Point1 has x: %f and y: %f\n",p1.x,p1.y);

	struct Point p2;
	xval = 2;
	yval = 1;
	setPoint(&p2,xval,yval);
	//printf("Point2 has x: %f and y: %f\n",p2.x,p2.y);

	//m = getSlope(p1,p2);
	//printf("Slope of Line joining p1 and p2: %f\n",m);

	//p2 = getIntersectPoint(line1,line2);
	//printf("Intersection Point of Line1 and Line2 has x: %f and y: %f\n",p2.x,p2.y);

	struct Square sq1;
	double xl,xr,yt,yb;

	xl = 2.00;
	xr = 4.00;
	yt = 4.00;
	yb = 2.00;
	setSquare(&sq1, xl, xr, yt, yb);
	printf("Sqaure1 has xleft: %0.3f, xright: %0.3f and ytop: %0.3f, ybottom: %0.3f\n",sq1.xleft,sq1.xright,sq1.ytop,sq1.ybottom);

	struct Point sqCentre1;
	sqCentre1 = getSquareCentre(sq1);
	printf("Centre Point of Square1 has x: %0.3f and y: %0.3f\n",sqCentre1.x,sqCentre1.y);

	struct Square sq2;
	xl = 10.00;
	xr = 12.00;
	yt = 8.00;
	yb = 6.00;
	setSquare(&sq2, xl, xr, yt, yb);
	printf("Sqaure2 has xleft: %0.3f, xright: %0.3f and ytop: %0.3f, ybottom: %0.3f\n",sq2.xleft,sq2.xright,sq2.ytop,sq2.ybottom);

	struct Point sqCentre2;
	sqCentre2 = getSquareCentre(sq2);
	printf("Centre Point of Square2 has x: %0.3f and y: %0.3f\n",sqCentre2.x,sqCentre2.y);

	m = getSlope(sqCentre1,sqCentre2);
	printf("Slope of Line joining Square 1 Centre and Square 2 Centre: %0.3f\n",m);

	c = getYintercept(m, sqCentre1);
	printf("Yintercept of Line joining Square 1 Centre and Square 2 Centre: %0.3f\n",c);

	struct Line linethruSqc;
	setLine(&linethruSqc,m,c);
	printf("Line through square centres has slope: %0.3f and y-intercept: %0.3f\n",linethruSqc.slope,linethruSqc.yintercept);

	return 0;
}

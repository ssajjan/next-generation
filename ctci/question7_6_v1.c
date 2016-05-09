/*
7.6
Given a two-dimensional graph with points on it, find a line which passes the most
number of points
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define EPSILON 0.000001

bool slopeIndeterminate = false;
bool slopeInfinite = false;

struct Point {
	double x;
	double y;
};

struct Line {
	double slope;
	double yintercept;
};

void setPoint(struct Point *point, double xval, double yval) {
	point->x = xval;
	point->y = yval;
}

void setLine(struct Line *line, double m, double c) {
	line->slope = m;
	line->yintercept = c;
}

double getSlope(struct Point p1, struct Point p2) {
	if (fabs(p2.x - p1.x) < EPSILON) {
		if (fabs(p2.y- p1.y) < EPSILON) {
			printf("Slope: Indeterminate since p1 and p2 are same points\n");
			slopeIndeterminate = true;
		}
		else {
			printf("Slope: Infinite(Parallel to y-axis)\n");
			slopeInfinite = true;
		}
		return 0;
	}
	else {
		return ((p2.y - p1.y)/(p2.x - p1.x));
	}
}

double getYintercept(struct Point p, double m) {
	return (p.y - m*p.x);
}

bool intersect(struct Line line1, struct Line line2) {
	return ((fabs(line1.slope - line2.slope) > EPSILON) ||
		(fabs(line1.yintercept - line2.yintercept) < EPSILON));
}

struct Point getIntersectionLL(struct Line line1, struct Line line2) {
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

struct Point getIntersectionPL(struct Line line, double Intercept, bool xgiven) {
	struct Point p;
	if (xgiven == true) {
		p.x = Intercept;
		p.y = (line.slope)*(p.x)+line.yintercept;
	}
	else {
		p.y = Intercept;
		p.x = (p.y-line.yintercept)/(line.slope);
	}
	return p;
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

        struct Point p1,p2,p3,p4,p5;
        double xval,yval;

        xval = 1;
        yval = 2;
        setPoint(&p1,xval,yval);
        printf("Point1 has x: %f and y: %f\n",p1.x,p1.y);

        xval = 2;
        yval = 1;
        setPoint(&p2,xval,yval);
        printf("Point2 has x: %f and y: %f\n",p2.x,p2.y);

        xval = 3;
        yval = 4;
        setPoint(&p3,xval,yval);
        printf("Point3 has x: %f and y: %f\n",p3.x,p3.y);

        xval = 4;
        yval = 3;
        setPoint(&p4,xval,yval);
        printf("Point4 has x: %f and y: %f\n",p4.x,p4.y);

        xval = 7;
        yval = 7;
        setPoint(&p5,xval,yval);
        printf("Point5 has x: %f and y: %f\n",p5.x,p5.y);

	double m,c;
        m = getSlope(p1,p2);
        printf("Slope of Line joining p1 and p2: %f\n",m);

	c = getYintercept(p1,m);
        printf("Yintercept of Line joining p1 and p2: %f\n",c);
	
	return 0;
}

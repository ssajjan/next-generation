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

struct PointsCollection {
	struct Point pt;
	struct PointsCollection *nextpt;
};

struct PointsCollection *pointsFront = NULL;
struct PointsCollection *pointsRear = NULL;

void addPoints(double xval, double yval) {
	printf("Adding Point: (%0.3f,%0.3f)\n",xval,yval);
	struct PointsCollection *pointsTemp;
	if (pointsFront == NULL && pointsRear == NULL) {
		pointsFront = (struct PointsCollection *)malloc(sizeof(struct PointsCollection));
		pointsFront->pt.x = xval;
		pointsFront->pt.y = yval;
		pointsFront->nextpt = pointsRear;
		pointsRear = pointsFront;
	}
	else {
		pointsTemp = (struct PointsCollection *)malloc(sizeof(struct PointsCollection));
		pointsTemp->pt.x = xval;
		pointsTemp->pt.y = yval;
		pointsRear->nextpt = pointsTemp;
		pointsRear = pointsTemp;
	}
}

void freePoints(void) {
	printf("Freeing points\n");
	struct PointsCollection *pointsTemp;
	while (pointsFront != NULL) {
		pointsTemp = pointsFront;
		printf("Point: (%0.3f,%0.3f)\n",pointsTemp->pt.x,pointsTemp->pt.y);
		pointsFront = pointsTemp->nextpt;
		pointsTemp->nextpt = NULL;
		free(pointsTemp);
	}
	pointsRear = NULL;
}

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

struct Line getProjectedLine(void) {
	double m,c;
	struct PointsCollection *current = NULL, *runner = NULL;
	struct Line l;

	current = pointsFront;
	while (current != NULL) {
		runner = current->nextpt;
		while (runner != NULL) {
        		m = getSlope(current->pt,runner->pt);
        		printf("Slope of Line joining p1 and p2: %f\n",m);
			c = getYintercept(runner->pt,m);
        		printf("Yintercept of Line joining p1 and p2: %f\n",c);
			printf("=====================================\n");

			runner = runner->nextpt;
		}
		current = current->nextpt;
	}

	return l;
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

        double xval,yval;

        xval = 1;
        yval = 2;
	addPoints(xval,yval);

        xval = 2;
        yval = 1;
	addPoints(xval,yval);

        xval = 3;
        yval = 4;
	addPoints(xval,yval);

        xval = 4;
        yval = 3;
	addPoints(xval,yval);

        xval = 7;
        yval = 7;
	addPoints(xval,yval);

	struct Line l;

	l = getProjectedLine();
        printf("Slope of Projected Line passing through given points: %f\n", l.slope);
        printf("Yintercept of Projected Line passing through given points: %f\n", l.yintercept);
	
	freePoints();
	return 0;
}

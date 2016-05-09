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

double getYintercept(double m, struct Point sqc1) {
	return (sqc1.y - m*sqc1.x);
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

	struct Square sq1;
	double xl,xr,yt,yb;

	xl = 2.00;
	xr = 4.00;
	yt = 4.00;
	yb = 2.00;
	setSquare(&sq1, xl, xr, yt, yb);
	printf("Sqaure1 has xleft: %0.3f, xright: %0.3f and ytop: %0.3f, ybottom: %0.3f\n",
		sq1.xleft,sq1.xright,sq1.ytop,sq1.ybottom);

	struct Point sqCentre1;
	sqCentre1 = getSquareCentre(sq1);
	printf("Centre Point of Square1 has x: %0.3f and y: %0.3f\n",sqCentre1.x,sqCentre1.y);

	struct Square sq2;
	xl = 12.00;
	xr = 10.00;
	yt = 6.00;
	yb = 4.00;
	setSquare(&sq2, xl, xr, yt, yb);
	printf("Sqaure2 has xleft: %0.3f, xright: %0.3f and ytop: %0.3f, ybottom: %0.3f\n",
		sq2.xleft,sq2.xright,sq2.ytop,sq2.ybottom);

	struct Point sqCentre2;
	sqCentre2 = getSquareCentre(sq2);
	printf("Centre Point of Square2 has x: %0.3f and y: %0.3f\n",sqCentre2.x,sqCentre2.y);

	double m,c;
	m = getSlope(sqCentre1,sqCentre2);
	printf("Slope of Line joining Square 1 Centre and Square 2 Centre: %0.3f\n",m);

	struct Line linethruSqc;
	if (slopeIndeterminate != true && slopeInfinite != true) {
		c = getYintercept(m, sqCentre1);
		printf("Yintercept of Line joining Square 1 Centre and Square 2 Centre: %0.3f\n",c);

		setLine(&linethruSqc,m,c);
		printf("Line through square centres has slope: %0.3f and y-intercept: %0.3f\n",
			linethruSqc.slope,linethruSqc.yintercept);
	}
	else {
		if (slopeIndeterminate == true) {
			printf("Both Squares have same Centre. "
			"Any line passing through this centre will divides squares into equal halves\n");

			printf("One example of Line through square centres is x = %0.3f\n",sqCentre1.x);
		}
		else if (slopeInfinite == true) {
			printf("Line with slope infinite wont have any y-intercept\n");

			printf("Line through square centres is x = %0.3f\n",sqCentre1.x);
		}
	}

	double starty,endy,startx,endx;
	if (slopeInfinite == true || slopeIndeterminate == true) {
		starty = (sq1.ytop > sq2.ytop)?sq1.ytop:sq2.ytop;
		endy = (sq1.ybottom > sq2.ybottom)?sq2.ybottom:sq1.ybottom;

		printf("Extrapolated line segment which cuts squares in equal halves is: "
			"(%0.3f,%0.3f)->(%0.3f,%0.3f)\n",sqCentre1.x,starty,sqCentre1.x,endy);
	}
	else if (linethruSqc.slope == 0) {
		startx = (sq1.xleft < sq2.xleft)?sq1.xleft:sq2.xleft;
		endx = (sq1.xright < sq2.xright)?sq2.xright:sq1.xright;

		printf("Extrapolated line segment which cuts squares in equal halves is: "
			"(%0.3f,%0.3f)->(%0.3f,%0.3f)\n",
			startx,linethruSqc.yintercept,endx,linethruSqc.yintercept);
	}
	else {
		//Find intersection point for Sq1
		struct Point ptArr[8], ipt;
		int count = 0;

		ipt = getIntersectionPL(linethruSqc,sq1.xleft,true);
		if (ipt.y >= sq1.ybottom && ipt.y <= sq1.ytop) {
			ptArr[count].x = ipt.x;
			ptArr[count].y = ipt.y;
			printf("1");
			printf("Intersection point has x: %0.3f and y: %0.3f\n",ptArr[count].x,ptArr[count].y);
			count++;
		}

		ipt = getIntersectionPL(linethruSqc,sq1.xright,true);
		if (ipt.y >= sq1.ybottom && ipt.y <= sq1.ytop) {
			ptArr[count].x = ipt.x;
			ptArr[count].y = ipt.y;
			printf("2");
			printf("Intersection point has x: %0.3f and y: %0.3f\n",ptArr[count].x,ptArr[count].y);
			count++;
		}

		ipt = getIntersectionPL(linethruSqc,sq1.ytop,false);
		if (ipt.x >= sq1.xleft && ipt.x <= sq1.xright) {
			ptArr[count].x = ipt.x;
			ptArr[count].y = ipt.y;
			printf("3");
			printf("Intersection point has x: %0.3f and y: %0.3f\n",ptArr[count].x,ptArr[count].y);
			count++;
		}

		ipt = getIntersectionPL(linethruSqc,sq1.ybottom,false);
		if (ipt.x >= sq1.xleft && ipt.x <= sq1.xright) {
			ptArr[count].x = ipt.x;
			ptArr[count].y = ipt.y;
			printf("4");
			printf("Intersection point has x: %0.3f and y: %0.3f\n",ptArr[count].x,ptArr[count].y);
			count++;
		}

		//Find intersection point for Sq2
		ipt = getIntersectionPL(linethruSqc,sq2.xleft,true);
		if (ipt.y >= sq2.ybottom && ipt.y <= sq2.ytop) {
			ptArr[count].x = ipt.x;
			ptArr[count].y = ipt.y;
			printf("5");
			printf("Intersection point has x: %0.3f and y: %0.3f\n",ptArr[count].x,ptArr[count].y);
			count++;
		}

		ipt = getIntersectionPL(linethruSqc,sq2.xright,true);
		if (ipt.y >= sq2.ybottom && ipt.y <= sq2.ytop) {
			ptArr[count].x = ipt.x;
			ptArr[count].y = ipt.y;
			printf("6");
			printf("Intersection point has x: %0.3f and y: %0.3f\n",ptArr[count].x,ptArr[count].y);
			count++;
		}

		ipt = getIntersectionPL(linethruSqc,sq2.ytop,false);
		if (ipt.x >= sq2.xleft && ipt.x <= sq2.xright) {
			ptArr[count].x = ipt.x;
			ptArr[count].y = ipt.y;
			printf("7");
			printf("Intersection point has x: %0.3f and y: %0.3f\n",ptArr[count].x,ptArr[count].y);
			count++;
		}

		ipt = getIntersectionPL(linethruSqc,sq2.ybottom,false);
		if (ipt.x >= sq2.xleft && ipt.x <= sq2.xright) {
			ptArr[count].x = ipt.x;
			ptArr[count].y = ipt.y;
			printf("8");
			printf("Intersection point has x: %0.3f and y: %0.3f\n",ptArr[count].x,ptArr[count].y);
			count++;
		}

		int index = 0;
		double minx = ptArr[index].x, maxx = ptArr[index].x;
		index++;

		while (index < count) {
			if (ptArr[index].x > maxx) {
				maxx = ptArr[index].x;
			}
			if (ptArr[index].x < minx) {
				minx = ptArr[index].x;
			}
			index++;
		}

		printf("Maximum x: %0.3f\n",maxx);
		printf("Minimum x: %0.3f\n",minx);

		struct Point startxy, endxy;
		index = 0;
		while (index < count) {
			if (fabs(ptArr[index].x - maxx) < EPSILON) {
				endxy = ptArr[index];
			}
			if (fabs(ptArr[index].x - minx) < EPSILON) {
				startxy = ptArr[index];
			}
			index++;
		}
		printf("Line segment cutting 2 squares equally: (%0.3f,%0.3f)-->(%0.3f,%0.3f)\n",
			startxy.x,startxy.y,endxy.x,endxy.y);
	}

	return 0;
}

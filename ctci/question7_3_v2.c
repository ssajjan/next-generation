/*
7.3
Given two lines on a Cartesian plane, determine whether the two lines would inter-
sect
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define EPSILON 0.000001

struct Line {
	double slope;
	double yintercept;
};

void setLine(struct Line *line, double m, double c) {
	line->slope = m;
	line->yintercept = c;
}

bool intersect(struct Line line1, struct Line line2) {
	return ((fabs(line1.slope - line2.slope) > EPSILON) || (fabs(line1.yintercept - line2.yintercept) < EPSILON));
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

	m = 1.00;
	c = 1.00;
	setLine(&line1,m,c);
	printf("Line1 has slope: %f and y-intercept: %f\n",line1.slope,line1.yintercept);

	struct Line line2;
	m = 1.00;
	c = 1.000001;
	setLine(&line2,m,c);
	printf("Line2 has slope: %f and y-intercept: %f\n",line2.slope,line2.yintercept);

	bool intrsct = false;
	intrsct = intersect(line1,line2);

	printf("Line1 and Line2 intersect: %s\n",intrsct==1?"True":"False");

	return 0;
}

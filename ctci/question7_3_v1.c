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

public class Line {
	static double epsilon = 0.000001;    /* relative error, used for floating point number comparisons*/
	public double slope;
	public double yintercept;

	public Line(double s, double y) {
		slope = s;
		yintercept = y;
	}

	public boolean intersect(Line Iine2) {
		return Math.abs(slope - Iine2.slope) > epsilon ||
			Math.abs(yintercept - Iine2.yintercept) < epsilon;
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

	return 0;
}

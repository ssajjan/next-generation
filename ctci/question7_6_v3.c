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
#define MAX_BUCKETS 10
#define MULTIPLIER 100
#define MAX_LEN 10

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

/* Hash Table Implementation*/
struct linerec {
        double slope;
        double yintercept;
        int count;
        struct linerec *next;
};

int hashstring (struct Line l) {
        int hash;
        hash= l.slope*MULTIPLIER + l.yintercept;
        return abs(hash)%MAX_BUCKETS;
}

struct linerec *lookup(struct linerec **table, struct Line l)
{
        struct linerec *curr = NULL;
        int hash = hashstring(l);
        printf("Hashstring for hash value %0.3f,%0.3f is %d\n",l.slope,l.yintercept,hash);
        struct linerec *wp,*nwp;

        if (table[hash]) {
                wp = table[hash];
        }
        else {
                printf("Assigning new memory for table[hash]\n");
                table[hash] = (struct linerec *)malloc(sizeof(struct linerec));
                memset(table[hash],0,sizeof(struct linerec));
                wp = table[hash];

        }

        int found = 0;
        for (curr = wp; curr != NULL; curr = curr->next) {
                /* search */
                printf("Curr pointer is %p with value %0.3f,%0.3f\n",curr,curr->slope,curr->yintercept);
                if ((fabs(curr->slope - l.slope) < EPSILON) && 
			(fabs(curr->yintercept - l.yintercept) < EPSILON)) {
                        found = 1;
                        curr->count++;
                        printf("Value %0.3f,%0.3f is already present in hash table\n",
								curr->slope,curr->yintercept);
                        break;
                }
        }

        if (found == 0) {
                if (wp->count>0) {
                        printf("Wp existing value for (%0.3f,%0.3f) is: (%0.3f,%0.3f) with count: %d\n",l.slope,l.yintercept,wp->slope,wp->yintercept,wp->count);
                        printf("Wp existing pointer is: %p\n",wp);
                        nwp = (struct linerec *)malloc(sizeof(struct linerec));
                        memset(nwp,0,sizeof(struct linerec));
                        printf("nWp new pointer is: %p\n",nwp);
                        nwp->slope = l.slope;
                        nwp->yintercept = l.yintercept;
                        nwp->count++;
                        nwp->next = wp;
                        printf("nWp value is: (%0.3f,%0.3f) with count: %d\n",nwp->slope,nwp->yintercept,nwp->count);
                        table[hash] = nwp;
                        curr = nwp;
                }
                else {
                        wp->slope = l.slope;
                        wp->yintercept = l.yintercept;
                        wp->count++;
                        curr = wp;
                        printf("New value: (%0.3f,%0.3f) count: %d\n",wp->slope,wp->yintercept,wp->count);
                }
                /* add to front */;
        }
        return curr;
}

void freedict(struct linerec **table) {
        struct linerec *curr,*temp;
        printf("\nFreeing the dict\n");
        for (int index = 0; index < MAX_LEN; index++) {
                if (table[index]) {
                        curr = table[index];
                        while (curr != NULL) {
                                printf("Curr pointer is %p with value %0.3f,%0.3f and count %d\n"
					,curr,curr->slope,curr->yintercept,curr->count);
                                temp = curr;
                                curr=curr->next;
                                free(temp);
                        }
                }
        }
}

/* Hash table implementation */

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
	printf("\nFreeing points\n");
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

struct Line findmaxline(struct linerec **table) {
        struct linerec *curr;
	struct Line l;
	int max = 1;

        for (int index = 0; index < MAX_LEN; index++) {
                if (table[index]) {
                        curr = table[index];
                        while (curr != NULL) {
				if (max < curr->count) {
					max = curr->count;
					setLine(&l,curr->slope,curr->yintercept);
				}
                                curr=curr->next;
                        }
                }
        }
	return l;
}

struct Line getProjectedLine(struct linerec **table) {
	double m,c;
	struct PointsCollection *current = NULL, *runner = NULL;
	struct Line l;
        struct linerec *dict;

	current = pointsFront;
	while (current != NULL) {
		runner = current->nextpt;
		while (runner != NULL) {
        		m = getSlope(current->pt,runner->pt);
        		printf("Slope of Line joining p1 and p2: %f\n",m);
			c = getYintercept(runner->pt,m);
        		printf("Yintercept of Line joining p1 and p2: %f\n",c);
			setLine(&l,m,c);

                	dict = lookup(table,l);
			printf("=====================================\n");

			runner = runner->nextpt;
		}
		current = current->nextpt;
	}

	return findmaxline(table);
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

        xval = 1; yval = 1;
	addPoints(xval,yval);

        xval = 2; yval = 3;
	addPoints(xval,yval);

        xval = 3; yval = 3;
	addPoints(xval,yval);

        xval = 4; yval = 4;
	addPoints(xval,yval);

        xval = 5; yval = 6;
	addPoints(xval,yval);

	struct Line l;

        struct linerec **table = (struct linerec **)malloc(sizeof(struct linerec)*MAX_LEN);  /* hash bucket */

	l = getProjectedLine(table);

        printf("\nSlope of Projected Line passing through given points: %f\n", l.slope);
        printf("Yintercept of Projected Line passing through given points: %f\n", l.yintercept);

	freePoints();
	freedict(table);
	return 0;
}

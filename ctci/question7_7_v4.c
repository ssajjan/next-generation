/*
7.7
Design an algorithm to find the kth number such that the only prime factors are 3,
5, and 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
	int val;
        struct node *next;
};

struct queue {
	struct node *qFront;
	struct node *qRear;
};

struct node *newNode(int num) {
	struct node *createN = NULL;
	createN = (struct node *)malloc(sizeof(struct node));
	if (createN != NULL) {
		createN->val = num;
		createN->next = NULL;
	}
	return createN;
}

struct queue *createQueue(void) {
	struct queue *createQ = NULL;
	createQ = (struct queue *)malloc(sizeof(struct queue));
	if (createQ != NULL) {
		createQ->qFront = NULL;
		createQ->qRear = NULL;
	}
	return createQ;
}

bool enqueue(struct queue *createdQ, int num) {
	if (!createdQ) {
		printf("Given Queue not created\n");
		return 0;
	}

	struct node *cursor = NULL;
	cursor = createdQ->qRear;
	if (!cursor) {
		/* Queue Empty */
		cursor = newNode(num);
		if (!cursor) {
			printf("Failed to allocate memory for Queue node\n");
			return 0;
		}
		createdQ->qFront = cursor;
		createdQ->qRear  = cursor;
	}
	else {
		cursor = newNode(num);
		if (!cursor) {
			printf("Failed to allocate memory for Queue node\n");
			return 0;
		}
		createdQ->qRear->next = cursor;
		createdQ->qRear = cursor;
	}
	return 1;
}

int dequeue(struct queue *createdQ) {
	if (!createdQ) {
		printf("Given Queue not created\n");
		return -1;
	}

	int num;
	struct node *cursor = NULL;
	cursor = createdQ->qFront;
	if (!cursor) {
		printf("Given Queue is empty\n");
		return -1;
	}
	else {
		num = cursor->val;
		if (!cursor->next) {
			free(cursor);
			createdQ->qFront = NULL;
			createdQ->qRear = NULL;
		}
		else {
			createdQ->qFront = cursor->next;
			free(cursor);
		}
		return num;
	}
}

int peekqueue(struct queue *createdQ) {
	if (!createdQ) {
		printf("Given Queue not created\n");
		return -1;
	}

	int num;
	struct node *cursor = NULL;
	cursor = createdQ->qFront;
	if (!cursor) {
		printf("Given Queue is empty\n");
		return -1;
	}
	else {
		num = cursor->val;
		return num;
	}
}

int removeMin(struct queue *createdQ) {
	if (!createdQ) {
		printf("Given Queue not created\n");
		return -1;
	}

	int min = peekqueue(createdQ);
	if (min == -1) {
		printf("Given Queue is empty\n");
		return -1;
	}

	struct node *cursor = NULL;
	cursor = createdQ->qFront;
	while (cursor != NULL) {
		if (min > cursor->val) {
			min = cursor->val;
		}
		cursor = cursor->next;
	}

	struct node *prev = NULL, *temp = NULL, *cursorNext = NULL;
	cursor = createdQ->qFront;
	while (cursor != NULL) {
		cursorNext = cursor->next;
		if (cursor->val == min) {
			if (!prev) {
				temp = cursor;
				if (!cursor->next) {
					createdQ->qFront = NULL;
					createdQ->qRear = NULL;
					free(temp);
				}
				else {
					createdQ->qFront = cursorNext;
					free(temp);
				}
			}
			else {
				temp = cursor;
				if (!cursor->next) {
					prev->next = NULL;
					createdQ->qRear = prev;
					free(temp);
				}
				else {
					prev->next = cursorNext;
					free(temp);
				}
			}
		}
		else {
			prev = cursor;
		}
		cursor = cursorNext;
	}
	return min;
}

bool printQueue(struct queue *createdQ) {
	if (!createdQ) {
		return 0;
	}

	struct node *cursor = NULL;
	cursor = createdQ->qFront;
	printf("Queue: ");
	while (cursor != NULL) {
		printf("%d,",cursor->val);
		cursor = cursor->next;
	}
	printf("\n");
	return 1;
}

bool freeQueue(struct queue *createdQ) {
	if (!createdQ) {
		return 0;
	}

	struct node *cursor = NULL;
	struct node *temp = NULL;

	cursor = createdQ->qFront;
	while (cursor != NULL) {
		temp = cursor;
		cursor = cursor->next;
		free(temp);
	}
	createdQ->qRear = NULL;

	free(createdQ);
	createdQ = NULL;

	return 1;
}

int main() {
	struct queue *q = NULL;
	q = createQueue();
	if (!q) {
		printf("Failed to allocate memory for Queue\n");
		return 1;
	}

	int num = 1, count = 1, k = 203;

	/* initialize Queue */
	enqueue(q,num*3);
	enqueue(q,num*5);
	enqueue(q,num*7);

	while (count<k) {
		num = removeMin(q);

		if (num != -1) {
			enqueue(q,num*3);
			enqueue(q,num*5);
			enqueue(q,num*7);
		}

		count++;
		//printQueue(q);
		printf("%d,",num);
	}
	printf("\n");

	//printf("K=%d number in 3,5,7 only series is: %d\n",k,num);
	freeQueue(q);

	return 0;
}

/*
7.7
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

	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	printQueue(q);
	printf("Queue Peek: %d\n",peekqueue(q));
	dequeue(q);
	enqueue(q,40);
	printQueue(q);
	printf("Queue Peek: %d\n",peekqueue(q));
	dequeue(q);
	printQueue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	printf("Queue Peek: %d\n",peekqueue(q));
	printQueue(q);
	enqueue(q,50);
	printQueue(q);

	freeQueue(q);

	return 0;
}

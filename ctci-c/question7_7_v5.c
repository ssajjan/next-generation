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

int getMinofQueues(struct queue *q3, struct queue *q5, struct queue *q7) {
	int min;
	
	/* checks for peekqueue */
	min = (peekqueue(q3) > peekqueue(q5))?(peekqueue(q5)):(peekqueue(q3));
	return ((min > peekqueue(q7))?(peekqueue(q7)):min);
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
	struct queue *q3 = NULL, *q5 = NULL, *q7 = NULL;
	q3 = createQueue();
	if (!q3) {
		printf("Failed to allocate memory for Queue\n");
		return 1;
	}

	q5 = createQueue();
	if (!q5) {
		printf("Failed to allocate memory for Queue\n");
		return 1;
	}
	q7 = createQueue();
	if (!q7) {
		printf("Failed to allocate memory for Queue\n");
		return 1;
	}

	int num = 1, count = 1, k = 50;

	/* initialize Queue */
	enqueue(q3,num*3);
	enqueue(q5,num*5);
	enqueue(q7,num*7);

	while (count<k) {
		num = getMinofQueues(q3,q5,q7);

		if (num < 0) {
			num = 1<<32
			break;
		}

		if (num == peekqueue(q3)) {
			num = dequeue(q3);
			enqueue(q3,num*3);
			enqueue(q5,num*5);
			enqueue(q7,num*7);
		}
		else if (num == peekqueue(q5)) {
			num = dequeue(q5);
			enqueue(q5,num*5);
			enqueue(q7,num*7);
		}
		if (num == peekqueue(q7)) {
			num = dequeue(q7);
			enqueue(q7,num*7);
		}

		count++;
		printQueue(q3);
		printQueue(q5);
		printQueue(q7);
		//printf("%d,",num);
	}
	//printf("\n");

	printf("K=%d number in 3,5,7 only series is: %d\n",k,num);
	freeQueue(q3);
	freeQueue(q5);
	freeQueue(q7);

	return 0;
}

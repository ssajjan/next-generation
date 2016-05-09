/*
2.5 
You have two numbers represented by a linked list, where each node contains a
single digit. The digits are stored in reverse order, such that the 1 's digit is at the head
of the list. Write a function that adds the two numbers and returns the sum as a
linked list.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 5

/* Linked List Implementation*/
struct node {
	int data; /* payload */
	struct node *next;
};

struct node * newNode(int data) {
	struct node *newNode =(struct node *) malloc(sizeof(struct node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;

	}

	return newNode;
}

struct node * appendNode(struct node *end, int data) {
	struct node *newEnd = newNode(data);
	if (newEnd != NULL && end != NULL) {
		end->next = newEnd;
	}

	return newEnd;
}

struct node * addNodetoFront(struct node *head, int data) {
	struct node *newHead = newNode(data);
	if (newHead != NULL) {
		newHead->next = head;
	}

	return newHead;
}

void iterateNodes(struct node *start) {
	printf("\nIterating over Linked List:\n");
	for (struct node *p = start; p!=NULL;p=p->next) {
		printf("Value: %d, Address: %p, Next Address: %p\n",p->data,p,p->next);
	}
	printf("\n");
}

struct node * findNthNode(struct node *start, int nthNode) {
	int index = 0;
	printf("Finding %dth node:\n",nthNode);
	while (start != NULL) {
		if (index == nthNode) {
			break;
		}
		index++;
		start = start->next;
	}

	return start;
}

bool delNthNode(struct node *midNode) {
	// Delete nth node without any head pointer of linked list given
	struct node *saveNextNode;
	if (midNode == NULL || midNode->next == NULL) {
		return false;
	}
	else {
		saveNextNode = midNode->next;
		midNode->data = saveNextNode->data;
		midNode->next = saveNextNode->next;
		free(saveNextNode);
		return true;
	}
}

struct node * findNode(struct node * curr, int val) {
	while (curr!= NULL) {
		if (curr->data == val)
			break;
		curr = curr->next;
	}

	return curr;
}

struct node * addLists(struct node *num1, struct node *num2) {
	struct node *sum = NULL;
	static struct node *saveEnd2 = NULL;
	int carry;
	static int count = 0;

	printf("Count: %d\n",count);
	if (num1->next != NULL) {
		count++;
		sum = addLists(num1->next,num2->next);
		count--;
		if (sum->data >=10) {
			sum->data = sum->data -10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		num1->data = num1->data + num2->data + carry;
		if (count > 0) {
			return num1;
		}
		else {
			if (num1->data >=10) {
				num1->data = num1->data - 10;
				saveEnd2->data = carry;
				saveEnd2->next = num1;
				num1 = saveEnd2;
				return num1;
			}
			else {
				return num1;
			}
		}
	}
	else {
		num1->data = num1->data + num2->data;
		saveEnd2 = num2;
		return num1;
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

	int num1[MAX_LEN] = {7,2,0,3,7};
	struct node *head1 = NULL; /* beginning */
	head1 = newNode(num1[4]);
	head1 = addNodetoFront(head1,num1[3]);
	head1 = addNodetoFront(head1,num1[2]);
	head1 = addNodetoFront(head1,num1[1]);
	head1 = addNodetoFront(head1,num1[0]);

	printf("Num1 : %d%d%d%d%d\n",num1[0],num1[1],num1[2],num1[3],num1[4]);
	iterateNodes(head1);

	int num2[MAX_LEN] = {1,8,9,7,1};
	struct node *head2 = NULL; /* beginning */
	head2 = newNode(num2[4]);
	head2 = addNodetoFront(head2,num2[3]);
	head2 = addNodetoFront(head2,num2[2]);
	head2 = addNodetoFront(head2,num2[1]);
	head2 = addNodetoFront(head2,num2[0]);

	printf("Num1 : %d%d%d%d%d\n",num2[0],num2[1],num2[2],num2[3],num2[4]);
	iterateNodes(head2);

	struct node *sum = NULL; /* beginning */
	sum = addLists(head1,head2);

	printf("\nFreeing Linked List sum:\n");
	struct node *temp;
	while (sum!=NULL) {
		printf("Value: %d, Address: %p, Next Address: %p\n",sum->data,sum,sum->next);
		temp = sum;
		sum=sum->next;
		free(temp);
	}

	printf("\nFreeing Linked List num 1:\n");
	while (head1!=NULL) {
		printf("Value: %d, Address: %p, Next Address: %p\n",head1->data,head1,head1->next);
		temp = head1;
		head1=head1->next;
		free(temp);
	}

	printf("\nFreeing Linked List num 2:\n");
	while (head2!=NULL) {
		printf("Value: %d, Address: %p, Next Address: %p\n",head2->data,head2,head2->next);
		temp = head2;
		head2=head2->next;
		free(temp);
	}

	//head = NULL;     /* Mark list as empty*/
	return 0;
}

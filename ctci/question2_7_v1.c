/*
2.7 
Implement a function to check if a linked list is a palindrome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 10

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

void iterateNodesCirc(struct node *start, struct node *circ) {
	printf("\nIterating over Circular Linked List:\n");
	struct node * p = start;
	while (p!= circ) {
		printf("Value: %d, Address: %p, Next Address: %p\n",p->data,p,p->next);
		p = p->next;
	}

	do {
		printf("Value: %d, Address: %p, Next Address: %p\n",p->data,p,p->next);
		p = p->next;
	}
	while (p != circ);
	printf("\n");
}

int findLen(struct node *start) {
	int len = 0;
	while (start!=NULL) {
		len++;
		start = start->next;
	}
	return len;
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

struct node * findLoop(struct node *start){
	struct node *curr = start;
	struct node *runn = start;
	while (curr != NULL) {
		if (runn->next == NULL || runn->next->next == NULL) {
			break;
		}
		else {
			curr = curr->next;
			runn = runn->next->next;
			if (curr == runn) {
				break;
			}
		}
	}

	if (curr == NULL || runn->next == NULL || runn->next->next == NULL) {
		printf("No circular component in Linked List\n");
		return NULL;
	}

	curr = start;
	while (1) {
		if (curr == runn) {
			break;
		}
		else {
			curr = curr->next;
			runn = runn->next;
		}
	}
	printf("Curr: %p, Value: %d\n", curr, curr->data);
	return curr;
}

struct node * getKthfromEnd(struct node *start, int index) {
	struct node *nodeKfromEnd = NULL;
	static int revCount;
	if (start->next != NULL) {
		nodeKfromEnd = getKthfromEnd(start->next, index);
		if (index == revCount) {
			printf("Node %d from end: %p, Value: %d\n",index,nodeKfromEnd,nodeKfromEnd->data); 
			return nodeKfromEnd;
		}
		else {
			revCount++;
			return start;
		}
	}
	else {
		revCount = 0;
		return start;
	}
}

bool isPalindrome(struct node *start) {
	struct node *curr = NULL, *runn = NULL;
	int index = 0;
	bool pFlag = true;

	curr = start;
	while (curr != NULL && curr != runn) {
		printf("Curr pointer: %p, Value: %d at index: %d from start\n",curr,curr->data,index);
		runn = getKthfromEnd(start, index);
		printf("Runn pointer: %p, Value: %d at index: %d from end\n",runn,runn->data,index);
		if (curr->data != runn->data) {
			pFlag = false;
			break;
		}
		else {
			index++;
			curr = curr->next;
		}
	}

	if (pFlag)
		return true;
	else
		return false;
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

	int num[MAX_LEN] = {7,2,0,3,5,3,0,2,7};
	//int num[MAX_LEN] = {7,2,0,3,5,5,3,0,2,7};
	struct node *head = NULL, *end = NULL; /* beginning */
	head = newNode(num[0]);
	end = head;
	end = appendNode(end,num[1]);
	end = appendNode(end,num[2]);
	end = appendNode(end,num[3]);
	end = appendNode(end,num[4]);
	end = appendNode(end,num[5]);
	end = appendNode(end,num[6]);
	end = appendNode(end,num[7]);
	end = appendNode(end,num[8]);

	iterateNodes(head);

	bool status = false;
	status = isPalindrome(head);

	if (status)
		printf("Linked List given is Palindrome\n");
	else
		printf("Linked List given is not a Palindrome\n");

	printf("\nFreeing Linked List:\n");
	struct node *temp;
	while (head != NULL) {
		printf("Value: %d, Address: %p, Next Address: %p\n",head->data,head,head->next);
		temp = head;
		head = head->next;
		free(temp);
	}
	//head = NULL;     /* Mark list as empty*/

	return 0;
}

// https://www.interviewcake.com/question/delete-node

#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* nextNode;

	void printNode()
	{
		Node* startNode = this;

		while (startNode != NULL)
		{
			printf("%d\n", startNode->value);
			startNode = startNode->nextNode;
		}
	}
};

void DeleteNode(Node* node)
{
	Node* nextNode = node->nextNode;

	node->value = nextNode->value;
	node->nextNode = nextNode->nextNode;

	free(nextNode);
}

int Delete_Node()
{
	Node* A = new Node();
	Node* B = new Node();
	Node* C = new Node();
	Node* D = new Node();

	A->value = 1;
	A->nextNode = B;
	B->value = 2;
	B->nextNode = C;
	C->value = 3;
	C->nextNode = D;
	D->value = 4;
	D->nextNode = NULL;

	DeleteNode(B);

	A->printNode();

	int test;
	cin >> test;

	return 0;
}
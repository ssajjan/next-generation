//https://www.interviewcake.com/question/reverse-linked-list?utm_source=weekly_email

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int value;
	Node* next;

	Node(int value, Node* next) :
		value(value), next(next)
	{

	}

	void Print()
	{
		Node* node = this;

		while (node != NULL)
		{
			printf("%d ", node->value);
			node = node->next;
		}
	}
};

Node* ReverseLinkedList(Node* list)
{
	Node* newHead = NULL;

	Node* cur = list;
	Node* prev = NULL;

	while (true)
	{
		Node* next = cur->next;

		cur->next = prev;

		prev = cur;
		cur = next;
		if (cur == NULL)
		{
			newHead = prev;
			break;
		}
	}

	return newHead;
}

//int main()
int Reverse_LinkedList()
{
	Node n1(1, NULL);
	Node n2(2, &n1);
	Node n3(3, &n2);
	Node n4(4, &n3);
	Node n5(5, &n4);

	n5.Print();
	cout << endl;

	Node* reverse = ReverseLinkedList(&n5);
	reverse->Print();

	Node n6(1, NULL);
	n6.Print();
	cout << endl;

	reverse = ReverseLinkedList(&n6);
	reverse->Print();

	int test;
	cin >> test;

	return 0;
}
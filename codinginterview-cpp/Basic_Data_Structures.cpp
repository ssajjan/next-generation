#include <iostream>

using namespace std;

struct LinkedList
{
	int value;
	LinkedList* nextNode;
};

class Queue
{
private:
	LinkedList* queue;
	LinkedList* backQueue;
	int size;

public:
	Queue() :
		queue(NULL),
		backQueue(NULL),
		size(0)
	{
	}

	void Enqueue(int value)
	{
		LinkedList* newNode = new LinkedList();
		newNode->value = value;
		newNode->nextNode = NULL;
		
		if (backQueue != NULL)
		{
			backQueue->nextNode = newNode;
		}
		else
		{
			queue = newNode;
		}

		backQueue = newNode;

		++size;
	}

	int Dequeue()
	{
		if (size > 0)
		{
			int returnValue = queue->value;

			LinkedList* dequeueNode = queue;
			queue = queue->nextNode;
			if (queue == NULL)
			{
				backQueue = NULL;
			}

			delete dequeueNode;
			--size;

			return returnValue;
		}
		else
		{
			throw exception("Empty queue");
		}
	}

	int length()
	{
		return size;
	}
};

class Stack
{
private:
	LinkedList* stack;
	int size;

public:
	Stack() :
		stack(NULL),
		size(0)
	{

	}

	int length()
	{
		return size;
	}

	void Push(int value)
	{
		LinkedList* newNode = new LinkedList();
		newNode->value = value;
		newNode->nextNode = stack;

		stack = newNode;

		++size;
	}

	int Peek()
	{
		return stack->value;
	}

	void Pop()
	{
		LinkedList* popNode = stack;
		stack = stack->nextNode;
		delete popNode;

		--size;
	}
};

struct NodeMaxStack
{
	int index = -1;
	int value = -1;
	NodeMaxStack* next;
};

class MaxStack
{
private:
	Stack stack;
	NodeMaxStack* maxVal;

public:
	MaxStack() :
		maxVal(NULL)
	{
	}

	void Push(int value)
	{
		stack.Push(value);

		if (maxVal == NULL || value > maxVal->value)
		{
			NodeMaxStack* newNode = new NodeMaxStack();
			newNode->index = stack.length();
			newNode->value = value;
			newNode->next = maxVal;
			maxVal = newNode;
		}
	}
	
	int Peek()
	{
		return stack.Peek();
	}

	void Pop()
	{
		if (stack.length() == maxVal->index)
		{
			NodeMaxStack* tmp = maxVal;
			maxVal = maxVal->next;
			free(tmp);
		}

		stack.Pop();
	}

	int GetMax()
	{
		return maxVal->value;
	}
};

class QueueTwoStack
{
private:
	Stack stack1, stack2;

public:
	void Enqueue(int value)
	{
		stack1.Push(value);
	}

	int Dequeue()
	{
		if (stack2.length() ==  0)
		{
			while (stack1.length() > 0)
			{
				stack2.Push(stack1.Peek());
				stack1.Pop();
			}
		}

		int value = stack2.Peek();
		stack2.Pop();
		return value;
	}
};

int Basic_Data_Structures()
//int main()
{
	Queue queue;
	queue.Enqueue(5);
	queue.Enqueue(10);
	queue.Enqueue(15);
	queue.Enqueue(20);
	queue.Enqueue(10);
	printf("%d\n", queue.Dequeue());
	printf("%d\n", queue.Dequeue());
	printf("%d\n", queue.Dequeue());
	printf("%d\n", queue.Dequeue());
	printf("%d\n", queue.Dequeue());
	cout << endl;

	QueueTwoStack queue2;
	queue2.Enqueue(5);
	queue2.Enqueue(10);
	queue2.Enqueue(15);
	printf("%d\n", queue2.Dequeue());
	printf("%d\n", queue2.Dequeue());
	queue2.Enqueue(20);
	queue2.Enqueue(10);
	printf("%d\n", queue2.Dequeue());
	printf("%d\n", queue2.Dequeue());
	printf("%d\n", queue2.Dequeue());
	cout << endl;

	Stack stack;
	stack.Push(5);
	stack.Push(10);
	stack.Push(15);
	stack.Push(20);
	stack.Push(10);
	printf("%d\n", stack.Peek());
	stack.Pop();
	printf("%d\n", stack.Peek());
	stack.Pop();
	printf("%d\n", stack.Peek());
	stack.Pop();
	printf("%d\n", stack.Peek());
	stack.Pop();
	printf("%d\n", stack.Peek());
	stack.Pop();
	cout << endl;

	MaxStack maxStack;
	maxStack.Push(10);
	maxStack.Push(5);
	maxStack.Push(10);
	maxStack.Push(15);
	maxStack.Push(20);
	maxStack.Push(10);
	printf("%d %d\n", maxStack.Peek(), maxStack.GetMax());
	maxStack.Pop();
	printf("%d %d\n", maxStack.Peek(), maxStack.GetMax());
	maxStack.Pop();
	printf("%d %d\n", maxStack.Peek(), maxStack.GetMax());
	maxStack.Pop();
	printf("%d %d\n", maxStack.Peek(), maxStack.GetMax());
	maxStack.Pop();
	printf("%d %d\n", maxStack.Peek(), maxStack.GetMax());
	maxStack.Pop();
	printf("%d %d\n", maxStack.Peek(), maxStack.GetMax());
	maxStack.Pop();

	int stop;
	cin >> stop;

	return 0;
}
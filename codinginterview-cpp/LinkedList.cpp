#include <iostream>
#include <vector>
#include "HelperMethod.h"

using namespace std;

void ReverseLinkedList(Node_LinkedList* node)
{
    if (node == NULL)
    {
        return;
    }

    Node_LinkedList* prev = NULL;
    Node_LinkedList* cur = node;
    Node_LinkedList* next = cur->nextNode;

    while (cur != NULL)
    {
        cur->nextNode = prev;
        prev = cur;
        cur = next;

        if (cur != NULL)
        {
            next = cur->nextNode;
        }
    }
}

Node_LinkedList* MergeLinkedList(Node_LinkedList* a, Node_LinkedList* b)
{
    Node_LinkedList* start = NULL;
    
    Node_LinkedList* last = NULL;
    while (true)
    {
        if (a == NULL)
        {
            if (last != NULL)
            {
                last->nextNode = b;
            }
            else
            {
                start = b;
            }

            break;
        }

        if (b == NULL)
        {
            if (last != NULL)
            {
                last->nextNode = a;
            }
            else
            {
                start = a;
            }

            break;
        }

        if (a->value > b->value)
        {
            if (last != NULL)
            {
                last->nextNode = a;
                last = a;
                a = a->nextNode;
            }
            else
            {
                last = a;
                start = a;
                a = a->nextNode;
            }
        }
        else
        {
            if (last != NULL)
            {
                last->nextNode = b;
                last = b;
                b = b->nextNode;
            }
            else
            {
                last = b;
                start = b;
                b = b->nextNode;
            }
        }
    }

    return start;
}

// int main()
int LinkedList()
{

    Node_LinkedList a(10, NULL);
    Node_LinkedList b(8, &a);
    Node_LinkedList c(6, &b);
    Node_LinkedList d(4, &c);
    d.Print();
    cout << endl;

    ReverseLinkedList(&d);
    a.Print();
    cout << endl;

    Node_LinkedList e(9, NULL);
    Node_LinkedList f(7, &e);
    Node_LinkedList g(5, &f);
    Node_LinkedList h(3, &g);
    h.Print();
    cout << endl;

    ReverseLinkedList(&h);
    e.Print();
    cout << endl;

    Node_LinkedList* merged = MergeLinkedList(&a, &e);
    merged->Print();
    cout << endl;

    int test;
    cin >> test;

    return 0;
}
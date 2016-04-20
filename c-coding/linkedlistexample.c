#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>

struct node{
    int data;
    struct node* next;;
};

//struct myStruct;
void changetoNull(struct node **headref)
{
	*headref=NULL;
	return;
}
void push(struct node** list, int data)
{
	struct node* temp;
	temp= (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = *list;
	*list = temp;
	
}

struct node* CreateList()
{
	struct node* l,*head = NULL;
	int count=0;
	
	
	for(count=1;count <6;count++)
	{	
		push(&head,count);
				
	}
	return head;
}

void PrintList(struct node* head)
{
	printf("\nList: ");
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

int main ()
{
	struct node* head= NULL;
	head = CreateList();
	PrintList(head);
	return 0;
}


#include<stdio.h> //printf, scanf
#include<stdlib.h> //malloc
#include<time.h>

typedef struct LinkListNode{
	int data;
	struct LinkListNode *next;
	
}Node_t;

int range(int start, int end)
{
    int randi = rand();
    int vals = (end - start) + 1;
    vals = vals*randi + start;
    return vals;
}

void Build_list(Node_t **headRef,int size){
	
	int i;
	for( i =0;i<size;i++){
		Node_t *node = (Node_t *)malloc(sizeof(Node_t));
		node->data = i;
#if 0 //STACK, -->  push to beginning of list on every increment
		node->next = *headRef;
		*headRef = node;
#else //QUEUE --> push to end  of list on every increment
		node->next = NULL;
		*headRef= node;
		headRef = &node->next;
#endif
	}
	return;
}


Node_t* push(Node_t **head, int data)
{
	Node_t* newnode = malloc(sizeof(Node_t));
	newnode->data=data;
	newnode->next=*head;
	//vvvvvvvvvvvvvvvv
	*head = newnode; //you say that now the new node is the head.
	//^^^^^^^^^^^^^^^^
	return newnode;
}

void insert_sorted_order(Node_t **head, int v_) 
{
    if (!head){
    	*head = malloc(sizeof(Node_t));
    	(*head)->data = v_;
	}else
    {
        Node_t* insert = malloc(sizeof(Node_t));
        insert->data = v_;
        Node_t** temp = head;
        
        while ((*temp) && insert->data > (*temp)->data)
			temp = &(*temp)->next;
        insert->next = (*temp);
        (*temp) = insert;
		
    }
}
Node_t* Pop(Node_t **headRef){
	Node_t *temp = *headRef;
	*headRef = (*headRef)->next;
	
	temp->next = NULL;
	return temp;
}

Node_t* RemoveNode(Node_t **headRef, int searchvalue){
	Node_t **temp = headRef;
	while(*temp && (*temp)->data!=searchvalue){
		temp = &(*temp)->next;
	}
	
	if(*temp == NULL)
		return NULL;
		
	Node_t *deletedNode = *temp;
	*temp = deletedNode->next;
	deletedNode->next = NULL;
	
	return deletedNode;
}

Node_t* RemoveNode_notemp(Node_t **headRef, int searchvalue){
	while(*headRef && (*headRef)->data!=searchvalue){
		headRef = &(*headRef)->next;
	}
	
	if(*headRef == NULL)
		return NULL;
		
	Node_t *deletedNode = *headRef;
	*headRef = deletedNode->next;
	deletedNode->next = NULL;
	
	return deletedNode;
}


void print_lints(Node_t *head){
	
	printf("List: ");
	while(head){
		printf("[0x%X]%4d -->",head, head->data);
		head = head->next;
	}
	printf("NULL\n");
	
}

int main(int argc, char** argv){
	Node_t *ll1 = NULL, *ll2=NULL;
	Build_list(&ll1,5);
	Build_list(&ll2,5);
	print_lints(ll1);
	print_lints(ll2);
	
	Node_t *top = RemoveNode_notemp(&ll1,3);
	printf("\n deleted ll1 list \n");
	print_lints(ll1);
	print_lints(top);

	Node_t *top_pop = Pop(&ll2);
	printf("\n poped ll2 list \n");
	print_lints(ll2);
	print_lints(top_pop);
	
	getchar();	
	
	return 0;
}

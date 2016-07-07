#include "binarytree.h"
#include <stack>

//Iterative functions
void preorderIterativeTraversal(Node *root){
	if(!root)
		return;
	
	cout<<endl<<__func__<<endl;
	stack<Node *> S;
	S.push(root);
	
	while(!S.empty()){
		Node *temp = S.top(); S.pop();
		cout<<temp->data<<" ";
		
		if(temp->right)
			S.push(temp->right);
		if(temp->left)
			S.push(temp->left);
	}
}

void inorderIterativeTraversal(Node *root){
	if(!root)
		return;
	
	cout<<endl<<__func__<<endl;
	stack<Node *> S;
	while(root->left){
		S.push(root);
		root = root->left;
	}
	S.push(root);

	while(!S.empty()){
		Node *temp = S.top();
		S.pop();
		cout<<temp->data<<" ";
		if(temp->right){
			temp = temp->right;
			while(temp->left){
				S.push(temp);
				temp = temp->left;
			}
			S.push(temp);
		}
	}
}

void postorderIterativeTraversal_2stack(Node *root){
	if(!root)
		return;
	cout<<endl<<__func__<<endl;
	stack<Node *> S1;
	stack<Node *> S2;
	Node * temp;

	S1.push(root);
	while(!S1.empty()){
		temp = S1.top();
		S1.pop();
		if(temp->left)
			S1.push(temp->left);
		if(temp->right)
			S1.push(temp->right);
		S2.push(temp);
	}

	while(!S2.empty()){
		temp= S2.top();
		cout<<temp->data<<" ";
		S2.pop();
	}
}

void postorderIterativeTraversal_1stack(Node *root){

	cout<<endl<<__func__<<endl;
	cout<<"Note yet";
}
void printLevelOrder(BinaryTree *head){

	if(head == NULL) 
		return;
	cout<<endl<<__func__<<endl;

	queue<BinaryTree *> Q;
	Q.push(head);

	while(Q.empty() == false){
		BinaryTree *node = Q.front();
		cout<< node->data <<" ";
		Q.pop();

		if(node->left != NULL)
			Q.push(node->left);
		if(node->right !=NULL)
			Q.push(node->right);
	}
}


// recurrence functions
void preorderRecurrenceTraversal(BinaryTree *root){
	if(root){
		cout<<root->data<<" ";
		preorderRecurrenceTraversal(root->left);
		preorderRecurrenceTraversal(root->right);
	}
}

void inorderRecurrenceTraversal(BinaryTree *root){
	if(root){
		preorderRecurrenceTraversal(root->left);
		cout<<root->data<<" ";
		preorderRecurrenceTraversal(root->right);
	}
}

void postorderRecurrenceTraversal(BinaryTree *root){
	if(root){
		preorderRecurrenceTraversal(root->left);
		preorderRecurrenceTraversal(root->right);
		cout<<root->data<<" ";
	}
}



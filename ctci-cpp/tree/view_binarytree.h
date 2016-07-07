#include "binarytree.h"

void leftView(Node *root){

	if(root)
		cout<<root->data<<" ";
	if(root->left)
		leftView(root->left);
	else if(root->right)
		leftView(root->right);
}

void rightView(Node *root){

	if(root)
		cout<<root->data<<" ";
	if(root->right)
		rightView(root->right);
	else if(root->left)
		rightView(root->left);
}

//http://www.geeksforgeeks.org/bottom-view-binary-tree/
void bottomView(Node *root){
}

//http://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/



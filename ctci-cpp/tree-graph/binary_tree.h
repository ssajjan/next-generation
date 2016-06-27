//g++ -o binary_tree_pretty_print.exe binary_tree_pretty_print.cpp

#include <fstream>
#include <iostream>
//#include <deque>
#include <queue>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

struct BinaryTree {
	int data;
	BinaryTree *left, *right;
	BinaryTree(int val) : left(NULL), right(NULL), data(val) { }
};

// Find the maximum height of the binary tree
int maxHeight(BinaryTree *p) {
	if (!p) return 0;
	int leftHeight = maxHeight(p->left);
	int rightHeight = maxHeight(p->right);
	return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

// Convert an integer value to string
// intTostring ,  integerTostring
string intToString(int val) {
	ostringstream ss;
	ss << val;
	return ss.str();
}

/* A function that constructs Balanced Binary Search Tree from a sorted array */
BinaryTree* sortedArrayToBST(int arr[],int start, int end){
	BinaryTree *root;

	if(start > end) return NULL;
	int mid = (start+end)/2;

	root = new BinaryTree(arr[mid]);
	root->left = sortedArrayToBST(arr, start, mid-1);
	root->right = sortedArrayToBST(arr,mid+1,end);
	
	return root;
}

void preorderTraversal(BinaryTree *root){
	if(root){
		preorderTraversal(root->left);
		cout<< root->data<< " ";
		preorderTraversal(root->right);
	}
}

// Print the arm branches (eg, /    \ ) on a line
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
	deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
	for (int i = 0; i < nodesInThisLevel / 2; i++) {  
		out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
		out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
	}
	out << endl;
}

// Print the branches and node (eg, ___10___ )
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
  deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->data) : "");
    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}

// Print the leaves only (just for the bottom row)
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
  deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->data) : "");
  }
  out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void printPretty(BinaryTree *root, int level, int indentSpace, ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)
    
  deque<BinaryTree*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    for (int i = 0; i < nodesInThisLevel; i++) {
      BinaryTree *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
	      nodesQueue.push_back(currNode->left);
	      nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

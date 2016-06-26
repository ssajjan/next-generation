//https://www.interviewcake.com/question/bst-checker
//http://www.geeksforgeeks.org/amazon-interview-experience-196-on-campus/

#include <iostream>
#include <time.h>
#include <sstream>
#include <functional>
#include <vector>
#include <stack>
#include "HelperMethod.h"

using namespace std;

bool BinarySearchTreeRecursive(Node_BinaryTree* node, int value, std::function<bool(int, int)> func)
{
    if (node == NULL)
    {
        return true;
    }

    if (!func(value, node->value))
    {
        return false;
    }

    return BinarySearchTreeRecursive(node->leftNode, node->value, std::greater_equal<int>()) &&
        BinarySearchTreeRecursive(node->rightNode, node->value, std::less_equal<int>());
}

bool BinarySearchTree(Node_BinaryTree* node)
{
    return BinarySearchTreeRecursive(node, node->value + 1, std::greater_equal<int>());
}

Node_BinaryTree* MergeBst(Node_BinaryTree* bst1, Node_BinaryTree* bst2)
{
    vector<int> bst1Val, bst2Val;
    bst1->ToSortedArray(bst1Val);
    bst2->ToSortedArray(bst2Val);

    vector<int> allVals;
    int index1 = 0, index2 = 0;
    while (true)
    {
        if (index1 >= bst1Val.size() && index2 >= bst2Val.size())
        {
            break;
        }

        int val1 = INT_MAX;
        if (index1 < bst1Val.size())
        {
            val1 = bst1Val[index1];
        }

        int val2 = INT_MAX;
        if (index2 < bst2Val.size())
        {
            val2 = bst2Val[index2];
        }

        if (val1 >= val2)
        {
            allVals.emplace_back(val2);
            ++index2;
        }
        else
        {
            allVals.emplace_back(val1);
            ++index1;
        }
    }

    return HelperMethod::generateBinarySearchTree(allVals, true);
}

Node_BinaryTree* InorderSucc(Node_BinaryTree* bst, int val, Node_BinaryTree* mostRecentSucc)
{
    if (bst->value > val)
    {
        if (mostRecentSucc == NULL || bst->value < mostRecentSucc->value)
        {
            mostRecentSucc = bst;
        }

        return InorderSucc(bst->leftNode, val, mostRecentSucc);
    }
    else if (bst->value < val)
    {
        return InorderSucc(bst->rightNode, val, mostRecentSucc);
    }
    else
    {
        if (bst->rightNode != NULL)
        {
            return bst->rightNode->MinNode();
        }
        else
        {
            return mostRecentSucc;
        }
    }
}

void sorted_order_printing_of_array_representing_complete_BST(const vector<int>& arrBst, int rootIndex)
{
    // Print left first
    if (rootIndex * 2 + 1 < arrBst.size())
    {
        sorted_order_printing_of_array_representing_complete_BST(arrBst, rootIndex * 2 + 1);
    }

    // Print root
    cout << arrBst[rootIndex] << " ";

    // Print right last
    if (rootIndex * 2 + 2 < arrBst.size())
    {
        sorted_order_printing_of_array_representing_complete_BST(arrBst, rootIndex * 2 + 2);
    }
}

bool isBst(Node_BinaryTree* root, int& sizeOfLargestsSbBST)
{
    bool returnVal = true;

    if (root == NULL)
    {
        sizeOfLargestsSbBST = 0;
        return true;
    }

    int maxSize = 0;

    int sizeLeft = 0;
    bool left = isBst(root->leftNode, sizeLeft);

    int sizeRight = 0;
    bool right = isBst(root->rightNode, sizeRight);

    if (left && right)
    {
        if (root->leftNode != NULL && root->leftNode->value > root->value)
        {
            returnVal = false;
        }

        if (root->rightNode != NULL && root->rightNode->value < root->value)
        {
            returnVal = false;
        }

        if (returnVal)
        {
            sizeOfLargestsSbBST = sizeLeft + sizeRight + 1;
        }
        else
        {
            sizeOfLargestsSbBST = sizeLeft > sizeRight ? sizeLeft : sizeRight;
        }
    }
    else if (left)
    {
        sizeOfLargestsSbBST = sizeLeft;
        returnVal = false;
    }
    else if (right)
    {
        sizeOfLargestsSbBST = sizeRight;
        returnVal = false;
    }

    return returnVal;
}

Node_BinaryTree* remove_node_out_of_range_BST(Node_BinaryTree* root, int min, int max)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node_BinaryTree* left = remove_node_out_of_range_BST(root->leftNode, min, max);
    Node_BinaryTree* right = remove_node_out_of_range_BST(root->rightNode, min, max);
    root->leftNode = left;
    root->rightNode = right;

    if (root->value < min)
    {
        delete(root);
        return right;
    }
    else if (root->value > max)
    {
        delete(root);
        return left;
    }

    return root;
}

void add_all_greater_value_to_node(Node_BinaryTree* root, int& add)
{
    if (root == NULL)
    {
        return;
    }

    add_all_greater_value_to_node(root->rightNode, add);

    int oldRoot = root->value;
    root->value = root->value + add;
    add += oldRoot;

    add_all_greater_value_to_node(root->leftNode, add);
}

int find_kth_smallest_element_BST(Node_BinaryTree* root, int& k)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    int leftResult = find_kth_smallest_element_BST(root->leftNode, k);
    if (k == 0)
    {
        return leftResult;
    }

    k--;
    if (k == 0)
    {
        return root->value;
    }

    return find_kth_smallest_element_BST(root->rightNode, k);
}

// int main()
int BinarySearchTree_Checker()
{
    srand(time(NULL));
    Node_BinaryTree* bt = HelperMethod::generateBinaryTree(true, 4);
    bt->Print();
    cout << endl;
    cout << "BST result = " << BinarySearchTree(bt) << endl;
    cout << endl;
    cout << endl;

    Node_BinaryTree* bst = HelperMethod::generateBinarySearchTree(true, 7);
    bst->Print();
    cout << endl;
    cout << "BST result = " << BinarySearchTree(bst) << endl;
    cout << endl;
    cout << endl;

    Node_BinaryTree* bst2 = HelperMethod::generateBinarySearchTree(true, 3);
    bst2->Print();
    cout << endl;
    cout << "BST result = " << BinarySearchTree(bst2) << endl;

    Node_BinaryTree* mergedBst = MergeBst(bst, bst2);
    mergedBst->Print();
    cout << endl;
    cout << "BST result = " << BinarySearchTree(mergedBst) << endl;

    int test;
    cin >> test;

    return 0;
}

// int main()
int Test_InsertSearchDeletePrintBST()
{
    srand(time(NULL));
    Node_BinaryTree* bst = HelperMethod::generateBinarySearchTree(true, 7);
    bst->Print();
    cout << endl;

    bst->InsertBST(20);
    bst->Print();
    cout << endl;

    bst->InsertBST(10);
    bst->Print();
    cout << endl;

    bst->InsertBST(30);
    bst->Print();
    cout << endl;

    bst->InsertBST(-30);
    bst->Print();
    cout << endl;

    bst->InsertBST(-40);
    bst->Print();
    cout << endl;

    Node_BinaryTree* bst2 = bst->SearchBST(20);
    bst2->Print();
    cout << endl;

    bst->DeleteBST(20);
    bst->Print();
    cout << endl;

    bst->DeleteBST(-30);
    bst->Print();
    cout << endl;

    int test;
    cin >> test;

    return 0;
}

// int main()
int Inorder_Succ()
{
    Node_BinaryTree* bst = new Node_BinaryTree();
    bst->value = 50;
    bst->InsertBST(10);
    bst->InsertBST(30);
    bst->InsertBST(40);
    bst->InsertBST(20);
    bst->InsertBST(55);
    bst->InsertBST(17);
    bst->InsertBST(19);
    bst->InsertBST(23);

    cout << InorderSucc(bst, 20, NULL)->value << endl;
    cout << InorderSucc(bst, 30, NULL)->value << endl;
    cout << InorderSucc(bst, 19, NULL)->value << endl;
    cout << InorderSucc(bst, 50, NULL)->value << endl;
    if (InorderSucc(bst, 55, NULL) == NULL)
    {
        cout << "55 has no successor" << endl;
    }

    int test;
    cin >> test;

    return 0;
}

// int main()
int sorted_order_printing_of_array_representing_complete_BST()
{
    vector<int> arrBst = { 4, 2, 5, 1, 3 };

    sorted_order_printing_of_array_representing_complete_BST(arrBst, 0);

    int test;
    cin >> test;

    return 0;
}

Node_BinaryTree* linked_list_to_BST(Node_LinkedList** head, int size)
{
    if (*head == NULL || size == 0)
    {
        return NULL;
    }

    if (size == 1)
    {
        Node_BinaryTree* newRoot = new Node_BinaryTree();
        newRoot->value = (*head)->value;
        *head = (*head)->nextNode;
        return newRoot;
    }

    Node_BinaryTree* leftTree = linked_list_to_BST(head, size / 2);
    
    Node_BinaryTree* newRoot = new Node_BinaryTree();
    newRoot->value = (*head)->value;
    *head = (*head)->nextNode;

    int rightSize = size - size / 2 - 1;
    Node_BinaryTree* rightTree = linked_list_to_BST(head, rightSize);

    newRoot->leftNode = leftTree;
    newRoot->rightNode = rightTree;

    return newRoot;
}

Node_BinaryTree* construct_BST_from_preorderArr(vector<int> preOrderArr, int& index, int min, int max)
{
    if (index >= preOrderArr.size())
    {
        return NULL;
    }

    if (preOrderArr[index] < min || preOrderArr[index] > max)
    {
        return NULL;
    }

    Node_BinaryTree* newRoot = new Node_BinaryTree();
    newRoot->value = preOrderArr[index];
    ++index;

    Node_BinaryTree* leftTree = construct_BST_from_preorderArr(preOrderArr, index, min, newRoot->value);

    Node_BinaryTree* rightTree = construct_BST_from_preorderArr(preOrderArr, index, newRoot->value, max);

    newRoot->leftNode = leftTree;
    newRoot->rightNode = rightTree;

    return newRoot;
}

Node_BinaryTree* construct_BST_from_preorderArr(vector<int> preOrderArr, int& index)
{
    return construct_BST_from_preorderArr(preOrderArr, index, INT_MIN, INT_MAX);
}

bool check_if_each_node_BST_has_only_one_child(const vector<int>& preOrderArr, int& index, int min, int max)
{
    if (index >= preOrderArr.size())
    {
        return true;
    }

    if (preOrderArr[index] < min || preOrderArr[index] > max)
    {
        return false;
    }

    int curValue = preOrderArr[index];
    ++index;

    if (preOrderArr[index] < curValue)
    {
        if (!check_if_each_node_BST_has_only_one_child(preOrderArr, index, min, curValue))
        {
            return false;
        }
    }
    else
    {
        if (!check_if_each_node_BST_has_only_one_child(preOrderArr, index, curValue, max))
        {
            return false;
        }
    }

    if (index != preOrderArr.size())
    {
        return false;
    }

    return true;
}

bool check_if_each_node_BST_has_only_one_child(const vector<int>& preOrderArr)
{
    int index = 0;
    return check_if_each_node_BST_has_only_one_child(preOrderArr, index, INT_MIN, INT_MAX);
}

void findPreSuc(Node_BinaryTree* root, Node_BinaryTree*& successor, Node_BinaryTree*& predecessor, int key)
{
    if (root == NULL)
    {
        return;
    }

    if (root->value == key)
    {
        if (root->leftNode != NULL)
        {
            predecessor = root->leftNode->MaxNode();
        }
        
        if (root->rightNode != NULL)
        {
            successor = root->rightNode->MinNode();
        }
    }
    else if (root->value > key)
    {
        if (successor == NULL || root->value < successor->value)
        {
            successor = root;
        }

        findPreSuc(root->leftNode, successor, predecessor, key);
    }
    else if (root->value < key)
    {
        if (predecessor == NULL || root->value > predecessor->value)
        {
            predecessor = root;
        }

        findPreSuc(root->rightNode, successor, predecessor, key);
    }
}

// int main()
int print_size_of_largest_subBSt()
{
    Node_BinaryTree* n1 = new Node_BinaryTree();
    Node_BinaryTree* n2 = new Node_BinaryTree();
    Node_BinaryTree* n3 = new Node_BinaryTree();
    Node_BinaryTree* n4 = new Node_BinaryTree();
    Node_BinaryTree* n5 = new Node_BinaryTree();
    Node_BinaryTree* n6 = new Node_BinaryTree();
    Node_BinaryTree* n7 = new Node_BinaryTree();
    Node_BinaryTree* n8 = new Node_BinaryTree();
    Node_BinaryTree* n9 = new Node_BinaryTree();

    n1->value = 50;
    n2->value = 30;
    n3->value = 60;
    n4->value = 5;
    n5->value = 20;
    n6->value = 45;
    n7->value = 70;
    n8->value = 65;
    n9->value = 80;

    n1->leftNode = n2;
    n1->rightNode = n3;

    n2->leftNode = n4;
    n2->rightNode = n5;

    n3->leftNode = n6;
    n3->rightNode = n7;

    n7->leftNode = n8;
    n7->rightNode = n9;

    int sizeOfLargestsSbBST = 0;
    isBst(n1, sizeOfLargestsSbBST);
    cout << sizeOfLargestsSbBST << endl;

    int test;
    cin >> test;

    return 0;
}

// int main()
int remove_node_out_of_range_BST()
{
    Node_BinaryTree* n1 = new Node_BinaryTree();
    Node_BinaryTree* n2 = new Node_BinaryTree();
    Node_BinaryTree* n3 = new Node_BinaryTree();
    Node_BinaryTree* n4 = new Node_BinaryTree();
    Node_BinaryTree* n5 = new Node_BinaryTree();
    Node_BinaryTree* n6 = new Node_BinaryTree();
    Node_BinaryTree* n7 = new Node_BinaryTree();

    n1->value = 6;
    n2->value = -13;
    n3->value = 14;
    n4->value = -8;
    n5->value = 13;
    n6->value = 15;
    n7->value = 7;

    n1->leftNode = n2;
    n1->rightNode = n3;
    
    n2->rightNode = n4;

    n3->leftNode = n5;
    n3->rightNode = n6;

    n5->leftNode = n7;

    Node_BinaryTree* newRoot = remove_node_out_of_range_BST(n1, -10, 13);
    newRoot->Print();

    int test;
    cin >> test;

    return 0;
}

// int main()
int add_all_greater_value_to_node()
{
    Node_BinaryTree* n1 = new Node_BinaryTree();
    Node_BinaryTree* n2 = new Node_BinaryTree();
    Node_BinaryTree* n3 = new Node_BinaryTree();
    Node_BinaryTree* n4 = new Node_BinaryTree();
    Node_BinaryTree* n5 = new Node_BinaryTree();
    Node_BinaryTree* n6 = new Node_BinaryTree();
    Node_BinaryTree* n7 = new Node_BinaryTree();

    n1->value = 50;
    n2->value = 30;
    n3->value = 70;
    n4->value = 20;
    n5->value = 40;
    n6->value = 60;
    n7->value = 80;

    n1->leftNode = n2;
    n1->rightNode = n3;

    n2->leftNode = n4;
    n2->rightNode = n5;

    n3->leftNode = n6;
    n3->rightNode = n7;

    int sum = 0;
    add_all_greater_value_to_node(n1, sum);
    n1->Print();

    int test;
    cin >> test;

    return 0;
}

// int main()
int find_kth_smallest_element_BST()
{
    Node_BinaryTree* n1 = new Node_BinaryTree();
    Node_BinaryTree* n2 = new Node_BinaryTree();
    Node_BinaryTree* n3 = new Node_BinaryTree();
    Node_BinaryTree* n4 = new Node_BinaryTree();
    Node_BinaryTree* n5 = new Node_BinaryTree();
    Node_BinaryTree* n6 = new Node_BinaryTree();
    Node_BinaryTree* n7 = new Node_BinaryTree();

    n1->value = 20;
    n2->value = 8;
    n3->value = 22;
    n4->value = 4;
    n5->value = 12;
    n6->value = 10;
    n7->value = 14;

    n1->leftNode = n2;
    n1->rightNode = n3;

    n2->leftNode = n4;
    n2->rightNode = n5;

    n5->leftNode = n6;
    n5->rightNode = n7;

    for (int i = 1; i <= 10; ++i)
    {
        int k = i;
        cout << find_kth_smallest_element_BST(n1, k) << endl;
    }

    int test;
    cin >> test;

    return 0;
}

// int main()
int linked_list_to_BST()
{
    Node_LinkedList* n1 = new Node_LinkedList();
    Node_LinkedList* n2 = new Node_LinkedList();
    Node_LinkedList* n3 = new Node_LinkedList();
    Node_LinkedList* n4 = new Node_LinkedList();
    Node_LinkedList* n5 = new Node_LinkedList();
    Node_LinkedList* n6 = new Node_LinkedList();
    Node_LinkedList* n7 = new Node_LinkedList();
    Node_LinkedList* n8 = new Node_LinkedList();

    n1->value = 1;
    n2->value = 2;
    n3->value = 3;
    n4->value = 4;
    n5->value = 5;
    n6->value = 6;
    n7->value = 7;
    n8->value = 8;

    n1->nextNode = n2;
    n2->nextNode = n3;
    n3->nextNode = n4;
    n4->nextNode = n5;
    n5->nextNode = n6;
    n6->nextNode = n7;
    n7->nextNode = n8;

    Node_LinkedList* tmp = n1;
    Node_BinaryTree* root = linked_list_to_BST(&tmp, 8);
    root->Print();

    int test;
    cin >> test;

    return 0;
}

// int main()
int construct_BST_from_preorderArr()
{
    vector<int> preOrderArr = { 20, 10, 11, 13, 12 };
    int index = 0;
    Node_BinaryTree* root = construct_BST_from_preorderArr(preOrderArr, index);
    root->Print();

    cout << endl;
    vector<int> preOrderArr2 = { 10, 5, 1, 7, 40, 50 };
    index = 0;
    root = construct_BST_from_preorderArr(preOrderArr2, index);
    root->Print();

    int test;
    cin >> test;

    return 0;
}

// int main()
int check_if_each_node_BST_has_only_one_child()
{
    vector<int> preOrderArr = { 20, 10, 11, 13, 12 };
    cout << check_if_each_node_BST_has_only_one_child(preOrderArr) << endl;

    cout << endl;
    vector<int> preOrderArr2 = { 10, 5, 1, 7, 40, 50 };
    cout << check_if_each_node_BST_has_only_one_child(preOrderArr2) << endl;

    int test;
    cin >> test;

    return 0;
}

// int main()
int inorder_successor_predecessor_in_BST()
{
    Node_BinaryTree* n1 = new Node_BinaryTree();
    Node_BinaryTree* n2 = new Node_BinaryTree();
    Node_BinaryTree* n3 = new Node_BinaryTree();
    Node_BinaryTree* n4 = new Node_BinaryTree();
    Node_BinaryTree* n5 = new Node_BinaryTree();
    Node_BinaryTree* n6 = new Node_BinaryTree();
    Node_BinaryTree* n7 = new Node_BinaryTree();

    n1->value = 50;
    n2->value = 30;
    n3->value = 70;
    n4->value = 20;
    n5->value = 40;
    n6->value = 60;
    n7->value = 80;

    n1->leftNode = n2;
    n1->rightNode = n3;

    n2->leftNode = n4;
    n2->rightNode = n5;

    n3->leftNode = n6;
    n3->rightNode = n7;

    Node_BinaryTree* successor = NULL;
    Node_BinaryTree* predecessor = NULL;
    findPreSuc(n1, successor, predecessor, 65);

    if (predecessor == NULL)
    {
        cout << "No predecessor" << endl;
    }
    else
    {
        cout << predecessor->value << endl;
    }

    if (successor == NULL)
    {
        cout << "No successor" << endl;
    }
    else
    {
        cout << successor->value << endl;
    }

    cout << endl;
    successor = NULL;
    predecessor = NULL;
    findPreSuc(n1, successor, predecessor, 20);

    if (predecessor == NULL)
    {
        cout << "No predecessor" << endl;
    }
    else
    {
        cout << predecessor->value << endl;
    }

    if (successor == NULL)
    {
        cout << "No successor" << endl;
    }
    else
    {
        cout << successor->value << endl;
    }

    cout << endl;
    successor = NULL;
    predecessor = NULL;
    findPreSuc(n1, successor, predecessor, 80);

    if (predecessor == NULL)
    {
        cout << "No predecessor" << endl;
    }
    else
    {
        cout << predecessor->value << endl;
    }

    if (successor == NULL)
    {
        cout << "No successor" << endl;
    }
    else
    {
        cout << successor->value << endl;
    }

    int test;
    cin >> test;

    return 0;
}
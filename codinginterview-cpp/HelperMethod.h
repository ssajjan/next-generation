#include <vector>
#include<limits.h>


struct Node_BinaryTree
{
    int value;
    Node_BinaryTree* leftNode;
    Node_BinaryTree* rightNode;
    Node_BinaryTree* nextNode;
    int level;
    int parentVal;

    Node_BinaryTree() :
        value(INT_MIN),
        leftNode(NULL),
        rightNode(NULL),
        nextNode(NULL)
    {
    }

    Node_BinaryTree(int value, Node_BinaryTree* left, Node_BinaryTree* right) :
        value(value), leftNode(left), rightNode(right)
    {
    }

    void Print();

    void ToSortedArray(std::vector<int>& result);

    void InsertBST(int val);

    Node_BinaryTree* DeleteBST(int val);

    Node_BinaryTree* SearchBST(int val);

    Node_BinaryTree* MinNode();

    Node_BinaryTree* MaxNode();
};

struct Node_LinkedList {
    int value;
    Node_LinkedList* nextNode;
    Node_LinkedList* previousNode;

    Node_LinkedList() :
        value(INT_MIN),
        nextNode(NULL),
        previousNode(NULL)
    {
    }

    Node_LinkedList(int value, Node_LinkedList* nextNode) :
        value(value), nextNode(nextNode)
    {
    }

    void Print()
    {
        printf("%d ", value);

        if (nextNode != NULL)
        {
            nextNode->Print();
        }
    }
};

class HelperMethod
{
public:
    static int binarySearch(const std::vector<int>& sortedArr, int elem);

    static int quickSearch(const std::vector<int>& arr, int k);

	static void printArray(const std::vector<int>& arr);

	static void printMatrix(const std::vector<std::vector<int> >& matrix);

	static void generateArray(std::vector<int>& arr, int size, int min, int max);

	static void generateMatrix(std::vector<std::vector<int>>& matrix, int width, int height, int min, int max);

    static Node_BinaryTree* generateBinaryTree(bool balance = false, int maxdepth = 10);

    static Node_BinaryTree* generateBinarySearchTree(std::vector<int> vals, bool balance = true);

    static Node_BinaryTree* generateBinarySearchTree(bool balance = true, int numVal = 31);

    static Node_BinaryTree* generateBinarySearchTree(bool balance, const std::vector<int>& val, int start, int end);

    // Heap related methods
    static void Heapify(std::vector<int>& arr);

    static void Heapify(std::vector<int>& arr, int index, int heapSize);

    static void IncreaseKey(std::vector<int>& arr, int index, int newVal);

    static void InsertHeap(std::vector<int>& arr, int al);
    
    static int RemoveLargestHeap(std::vector<int>& arr);

    static void HeapSort(std::vector<int>& arr);

    static void BuildMaxHeap(std::vector<int>& arr);

    static int LeftHeap(int index);

    static int RightHeap(int index);

    static int ParentHeap(int index);

    // Sorted related methods
    static void mergeSort(std::vector<int>& arr);

    static void mergeSort(std::vector<int>& arr, int low, int high);

    static void quickSort(std::vector<int>& arr);

    static void quickSort(std::vector<int>& arr, int low, int high);
};

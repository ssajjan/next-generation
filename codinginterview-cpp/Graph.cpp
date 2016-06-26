#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include "HelperMethod.h"

using namespace std;

struct AdGraph
{
    struct AdList
    {
        int dest;
        int weight;
        AdList* next;
    };

    vector<AdList*> list;

    AdGraph(int numV)
    {
        list.resize(numV, NULL);
    }

    void addEdge(int src, int dst, int weight)
    {
        AdList* list = new AdList();
        list->dest = dst;
        list->weight = weight;


    }
};

struct NodeGraph
{
    int val;
    vector<NodeGraph*> dst;

    void Print()
    {
        queue<NodeGraph*> toPrint;
        set<NodeGraph*> visited;
        toPrint.push(this);
        visited.insert(this);

        while (!toPrint.empty())
        {
            NodeGraph* top = toPrint.front();
            toPrint.pop();

            cout << top->val << " ";
            for (int i = 0; i < top->dst.size(); ++i)
            {
                if (visited.find(top->dst[i]) == visited.end())
                {
                    toPrint.push(top->dst[i]);
                    visited.insert(top->dst[i]);
                }
            }
        }
        cout << endl;
    }
};

struct Graph {
    int numVertices;
    vector<vector<int>> edges;

    Graph(int numVertices) :
        numVertices(numVertices)
    {
        edges.resize(numVertices);
    }

    void addEdge(int source, int dest)
    {
        edges[source].emplace_back(dest);
    }

    void addUndirectedEdge(int source, int dest)
    {
        edges[source].emplace_back(dest);
        edges[dest].emplace_back(source);
    }

    void BFS(int startNode)
    {
        if (startNode < 0 || startNode >= numVertices)
        {
            return;
        }

        queue<int> toVisit;
        set<int> visited;
        toVisit.push(startNode);

        while (!toVisit.empty())
        {
            int nextNode = toVisit.front();
            toVisit.pop();
            visited.insert(nextNode);

            cout << nextNode << " ";
            for (int i = 0; i < edges[nextNode].size(); ++i)
            {
                if (visited.find(edges[nextNode][i]) == visited.end())
                {
                    toVisit.push(edges[nextNode][i]);
                }
            }
        }
        cout << endl;
    }

    void DFS(int startNode)
    {
        if (startNode < 0 || startNode >= numVertices)
        {
            return;
        }

        stack<int> toVisit;
        set<int> visited;
        toVisit.push(startNode);

        while (!toVisit.empty())
        {
            int nextNode = toVisit.top();
            toVisit.pop();
            visited.insert(nextNode);

            cout << nextNode << " ";
            for (int i = 0; i < edges[nextNode].size(); ++i)
            {
                if (visited.find(edges[nextNode][i]) == visited.end())
                {
                    toVisit.push(edges[nextNode][i]);
                }
            }
        }
        cout << endl;
    }

    bool isCycle()
    {
        if (numVertices == 0)
        {
            return false;
        }

        queue<int> toVisit;
        for (int i = 0; i < this->numVertices; ++i)
        {
            toVisit.push(i);
        }

        while (!toVisit.empty())
        {
            int nextNode = toVisit.front();
            toVisit.pop();

            set<int> visited;
            queue<int> toCheck;
            toCheck.push(nextNode);
            while (!toCheck.empty())
            {
                int nextCheck = toCheck.front();
                toCheck.pop();
                visited.insert(nextCheck);

                for (int i = 0; i < this->edges[nextCheck].size(); ++i)
                {
                    if (visited.find(this->edges[nextCheck][i]) != visited.end())
                    {
                        return true;
                    }

                    toCheck.push(this->edges[nextCheck][i]);
                }
            }
        }

        return false;
    }
};

struct Graph2
{
    vector<vector<int>> graph;

    Graph2(int numVertices)
    {
        graph.resize(numVertices);
        for (int i = 0; i < graph.size(); ++i)
        {
            graph[i].resize(numVertices, 0);
        }
    }

    void addEdge(int src, int dest)
    {
        graph[src][dest] = 1;
    }

    void addEdge(int src, int dest, int weight)
    {
        graph[src][dest] = weight;
    }
};

template<typename Type>
Type add(Type a, Type b)
{
    return a + b;
}

/* void CopyGraph(NodeGraph*& copy, NodeGraph* node, map<NodeGraph*, NodeGraph*>& oldToNew)
{
    if (node == NULL)
    {
        if (copy != NULL)
        {
            delete copy;
            copy = NULL;
        }

        return;
    }

    copy->val = node->val;
    oldToNew.insert(std::make_pair(node, copy));
    for (int i = 0; i < node->dst.size(); ++i)
    {
        if (oldToNew.find(node->dst[i]) == oldToNew.end())
        {
            copy->dst.emplace_back(new NodeGraph());
            CopyGraph(copy->dst[i], node->dst[i], oldToNew);
        }
        else
        {
            copy->dst.emplace_back(oldToNew[node->dst[i]]);
        }
    }
} */

void merge_sort(vector<int>& arr)
{
    if (arr.size() <= 1)
    {
        return;
    }

    const int size = arr.size();
    const int sizeLeft = size / 2;

    vector<int> arrLeft(arr.begin(), arr.begin() + sizeLeft);
    vector<int> arrRight(arr.begin() + sizeLeft, arr.begin() + size);

    merge_sort(arrLeft);
    merge_sort(arrRight);

    int left = 0;
    int right = 0;
    while (left < arrLeft.size() || right < arrRight.size())
    {
        if (left == arrLeft.size())
        {
            arr[left + right] = arrRight[right];
            ++right;
        }
        else if (right == arrRight.size())
        {
            arr[left + right] = arrLeft[left];
            ++left;
        }
        else
        {
            if (arrLeft[left] < arrRight[right])
            {
                arr[left + right] = arrLeft[left];
                ++left;
            }
            else
            {
                arr[left + right] = arrRight[right];
                ++right;
            }
        }
    }
}

void dijkstra(const vector<vector<int>>& graph, int src)
{
    vector<bool> visited(graph.size(), false);
    visited[src] = true;

    vector<int> distance(graph.size(), INT_MAX);
    distance[src] = 0;

    for (int i = 0; i < graph.size(); ++i)
    {
        if (graph[src][i] > 0)
        {
            distance[i] = graph[src][i];
        }
    }

    while (true)
    {
        int minDist = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < distance.size(); ++i)
        {
            if (visited[i] == false && distance[i] < minDist && distance[i] > 0)
            {
                minDist = distance[i];
                minIndex = i;
            }
        }

        if (minIndex == -1)
        {
            break;
        }

        visited[minIndex] = true;

        for (int i = 0; i < distance.size(); ++i)
        {
            if (graph[minIndex][i] > 0 && graph[minIndex][i] + distance[minIndex] < distance[i])
            {
                distance[i] = graph[minIndex][i] + distance[minIndex];
            }
        }
    }

    HelperMethod::printArray(distance);
}

//http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
// int main()
int detect_cyle_in_graph()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << g.isCycle() << endl;

    Graph g2(4);
    g2.addEdge(3, 0);
    g2.addEdge(3, 1);
    g2.addEdge(3, 2);
    g2.addEdge(1, 2);
    cout << g2.isCycle() << endl;

    Graph g3(4);
    g3.addEdge(3, 0);
    g3.addEdge(3, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    cout << g3.isCycle() << endl;

    int test;
    cin >> test;

    return 0;
}

//http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
//int main()
int BFS()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);
    g.DFS(2);

    int test;
    cin >> test;

    return 0;
}

//int main()
int BFS2()
{
    NodeGraph* node1 = new NodeGraph();
    node1->val = 1;

    NodeGraph* node2 = new NodeGraph();
    node2->val = 3;

    NodeGraph* node3 = new NodeGraph();
    node3->val = 2;

    NodeGraph* node4 = new NodeGraph();
    node4->val = 4;

    NodeGraph* node5 = new NodeGraph();
    node5->val = 5;

    node1->dst.emplace_back(node2);
    node1->dst.emplace_back(node3);
    node2->dst.emplace_back(node4);
    node3->dst.emplace_back(node5);
    node2->dst.emplace_back(node1);

    map<NodeGraph*, NodeGraph*> oldToNew;
    NodeGraph* copy = new NodeGraph();
    //CopyGraph(copy, node1, oldToNew);

    node1->Print();
    cout << endl;
    copy->Print();

    cout << add<string>("con vit ", "con ngan") << endl;

    int test;
    cin >> test;

    return 0;
}

//int main()
int merge_sort()
{
    vector<int> arr;
    HelperMethod::generateArray(arr, 10, 0, 1000);
    HelperMethod::printArray(arr);

    merge_sort(arr);
    HelperMethod::printArray(arr);

    int test;
    cin >> test;

    return 0;
}

// int main()
int dijkstras1()
{
    vector<vector<int>> graph =
    { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    { 0, 0, 4, 0, 10, 0, 2, 0, 0 },
    { 0, 0, 0, 14, 0, 2, 0, 1, 6 },
    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    dijkstra(graph, 0);

    int test;
    cin >> test;

    return 0;
}

// int main()
int dijkstras2()
{
    int V = 9;
    struct AdGraph graph(V);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);

    // dijkstras2(graph, 0);

    int test;
    cin >> test;

    return 0;
}
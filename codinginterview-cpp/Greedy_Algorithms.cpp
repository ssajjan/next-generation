#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

struct Edge
{
    int src;
    int dest;
    int weight;

    Edge(int src, int dest, int weight) :
        src(src),
        dest(dest),
        weight(weight)
    {
    }
};

struct Graph
{
    int E, V;
    vector<Edge> edges;
};

struct Job
{
    char name;
    int deadline;
    int profit;
};

int JobCompare(const void* j1, const void* j2)
{
    return ((Job*)(j2))->profit - ((Job*)(j1))->profit;
}

/*
// Recursive version

void job_sequencing_scheduling(const vector<Job>& arr, int curTime, vector<Job>& curJobs, vector<Job>& maxJobs, int& maxProfit)
{
    vector<Job> possibleJob;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i].deadline > curTime)
        {
            bool found = false;
            for (int j = 0; j < curJobs.size(); ++j)
            {
                if (arr[i].name == curJobs[j].name)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                possibleJob.emplace_back(arr[i]);
            }
        }
    }

    if (possibleJob.empty())
    {
        int profit = 0;
        for (int i = 0; i < curJobs.size(); ++i)
        {
            profit += curJobs[i].profit;
        }

        if (profit > maxProfit)
        {
            maxJobs = curJobs;
            maxProfit = profit;
        }

        return;
    }

    for (int i = 0; i < possibleJob.size(); ++i)
    {
        curJobs.emplace_back(possibleJob[i]);
        job_sequencing_scheduling(possibleJob, curTime + 1, curJobs, maxJobs, maxProfit);
        curJobs.pop_back();
    }
}

void job_sequencing_scheduling(const vector<Job>& arr)
{
    vector<Job> curJobs;
    vector<Job> maxJobs;
    int maxProfit = 0;
    job_sequencing_scheduling(arr, 0, curJobs, maxJobs, maxProfit);

    for (int i = 0; i < maxJobs.size(); ++i)
    {
        cout << maxJobs[i].name << " ";
    }

    cout << endl;
} */

void job_sequencing_scheduling(vector<Job>& arr)
{
    qsort(&(arr[0]), arr.size(), sizeof(Job), JobCompare);

    vector<char> timeSlots(arr.size(), ' ');

    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = timeSlots.size() - 1; j >= 0; --j)
        {
            if (timeSlots[j] == ' ' && arr[i].deadline > j)
            {
                timeSlots[j] = arr[i].name;
                break;
            }
        }
    }

    for (int i = 0; i < timeSlots.size(); ++i)
    {
        if (timeSlots[i] != ' ')
        {
            cout << timeSlots[i] << " ";
        }
    }
    cout << endl;
}

void dijkstra_shortest_path(vector<vector<int>>& graph, int source)
{
    vector<bool> include(graph.size(), false);
    vector<int> costs(graph.size(), INT_MAX);
    costs[source] = 0;

    int count = 0;
    while (count < graph.size())
    {
        int minIndex = 0;
        int minCost = INT_MAX;
        for (int i = 0; i < costs.size(); ++i)
        {
            if (include[i] == false && minCost > costs[i])
            {
                minIndex = i;
                minCost = costs[i];
            }
        }

        include[minIndex] = true;
        for (int i = 0; i < graph[minIndex].size(); ++i)
        {
            if (include[i] == false && graph[minIndex][i] > 0 && costs[minIndex] + graph[minIndex][i] < costs[i])
            {
                costs[i] = costs[minIndex] + graph[minIndex][i];
            }
        }

        ++count;
    }

    for (int i = 0; i < costs.size(); ++i)
    {
        cout << i << " " << costs[i] << endl;
    }
}

void dijkstra_shortest_path(Graph& graph, int source, int dest)
{
    int size = graph.edges.size();
    vector<bool> found(size, false);
    vector<int> parents(size, INT_MIN);
    vector<int> costs(size, INT_MAX);
    costs[source] = 0;

    cout << endl;
    for (int i = 0; i < size; ++i)
    {
        int minIndex = 0;
        int minCost = INT_MAX;
        for (int i = 0; i < costs.size(); ++i)
        {
            if (found[i] == false && costs[i] < minCost)
            {
                minCost = costs[i];
                minIndex = i;
            }
        }

        found[minIndex] = true;

        for (int i = 0; i < graph.edges.size(); ++i)
        {
            if (found[graph.edges[i].dest] == false || found[graph.edges[i].src] == false)
            {
                if (graph.edges[i].src == minIndex)
                {
                    if (costs[minIndex] + graph.edges[i].weight < costs[graph.edges[i].dest])
                    {
                        costs[graph.edges[i].dest] = costs[minIndex] + graph.edges[i].weight;
                        parents[graph.edges[i].dest] = minIndex;
                    }
                }
                else if (graph.edges[i].dest == minIndex)
                {
                    if (costs[minIndex] + graph.edges[i].weight < costs[graph.edges[i].src])
                    {
                        costs[graph.edges[i].src] = costs[minIndex] + graph.edges[i].weight;
                        parents[graph.edges[i].src] = minIndex;
                    }
                }
            }
        }
    }

    cout << "Shortest path in reverse " << endl;
    int curIndex = dest;

    while (curIndex != source)
    {
        cout << curIndex << " ";
        curIndex = parents[curIndex];
    }
    cout << source << " " << endl;
}

void dijkstra_shortest_path(vector<vector<int>>& graph, int source, int dest)
{
    vector<bool> include(graph.size(), false);
    vector<int> costs(graph.size(), INT_MAX);
    costs[source] = 0;

    int count = 0;
    while (count < graph.size())
    {
        int minIndex = 0;
        int minCost = INT_MAX;
        for (int i = 0; i < costs.size(); ++i)
        {
            if (include[i] == false && minCost > costs[i])
            {
                minIndex = i;
                minCost = costs[i];
            }
        }

        include[minIndex] = true;
        for (int i = 0; i < graph[minIndex].size(); ++i)
        {
            if (include[i] == false && graph[minIndex][i] > 0 && costs[minIndex] + graph[minIndex][i] < costs[i])
            {
                costs[i] = costs[minIndex] + graph[minIndex][i];
            }
        }

        ++count;
    }

    stack<int> path;
    path.push(dest);
    int cost = costs[dest];
    int curIndex = dest;
    while (cost > 0)
    {
        for (int i = 0; i < graph[curIndex].size(); ++i)
        {
            if (graph[curIndex][i] > 0 && costs[i] == cost - graph[curIndex][i])
            {
                curIndex = i;
                cost = costs[i];
                path.push(i);
                break;
            }
        }
    }

    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
}

void prim_minimum_spanning_tree(vector<vector<int>> graph)
{
    int size = graph.size();
    vector<bool> steps(size, false);
    vector<int> costs(size, INT_MAX);
    vector<int> parents(size, INT_MIN);
    steps[0] = false;
    costs[0] = 0;

    for (int i = 0; i < size; ++i)
    {
        int minIndex = -1;
        int minCost = INT_MAX;
        for (int j = 0; j < size; ++j)
        {
            if (steps[j] == false && costs[j] < minCost)
            {
                minIndex = j;
                minCost = costs[j];
            }
        }

        steps[minIndex] = true;

        for (int j = 0; j < size; ++j)
        {
            if (graph[minIndex][j] > 0 && steps[j] == false && graph[minIndex][j] < costs[j])
            {
                costs[j] = graph[minIndex][j];
                parents[j] = minIndex;
            }
        }
    }

    cout << "Minimum spanning tree " << endl;
    for (int i = 0; i < size; ++i)
    {
        if (parents[i] != INT_MIN)
        {
            cout << "Edges " << " " << i << " to " << parents[i] << " cost " << graph[i][parents[i]] << endl;
        }
    }
}

struct EdgeComparator
{
    EdgeComparator()
    {
    }

    bool operator() (const Edge& left, const Edge& right)
    {
        return left.weight > right.weight;
    }
};

void prim_minimum_spanning_tree(const Graph& graph)
{
    int size = graph.edges.size();
    priority_queue<Edge, vector<Edge>, EdgeComparator> possibleEdges;
    vector<bool> found(size, false);
    vector<Edge> tree;

    for (int i = 0; i < size; ++i)
    {
        if (graph.edges[i].src == 0 || graph.edges[i].dest == 0)
        {
            possibleEdges.push(graph.edges[i]);
        }
    }

    while (!possibleEdges.empty())
    {
        Edge edge = possibleEdges.top();
        possibleEdges.pop();
        if (found[edge.src] == true && found[edge.dest] == true)
        {
            continue;
        }

        tree.emplace_back(edge);
        found[edge.src] = true;
        found[edge.dest] = true;
        for (int i = 0; i < graph.edges.size(); ++i)
        {
            if ((graph.edges[i].src == edge.src || graph.edges[i].dest == edge.src ||
                graph.edges[i].src == edge.dest || graph.edges[i].dest == edge.dest) &&
                (found[graph.edges[i].src] == false || graph.edges[i].dest == false))
            {
                possibleEdges.push(graph.edges[i]);
            }
        }
    }

    cout << "Minimum spanning tree " << endl;
    for (int i = 0; i < tree.size(); ++i)
    {
        cout << "Edge " << tree[i].src << " " << tree[i].dest << " " << tree[i].weight << endl;
    }
}

// http://www.geeksforgeeks.org/job-sequencing-problem-set-1-greedy-algorithm/
// int main()
int job_sequencing_scheduling()
{
    vector<Job> arr = { { 'a', 2, 100 }, { 'b', 1, 19 }, { 'c', 2, 27 }, { 'd', 1, 25 }, { 'e', 3, 15 } };
    job_sequencing_scheduling(arr);

    vector<Job> arr2 = { { 'a', 4, 20 }, { 'b', 1, 10 }, { 'c', 1, 40 }, { 'd', 1, 30 } };
    job_sequencing_scheduling(arr2);

    int test;
    cin >> test;

    return 0;
}

// http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
// int main()
int dijkstra_shortest_path()
{
    vector<vector<int>> graph =
    {
    { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    { 0, 0, 4, 0, 10, 0, 2, 0, 0 },
    { 0, 0, 0, 14, 0, 2, 0, 1, 6 },
    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    dijkstra_shortest_path(graph, 0);

    cout << "Path from 0 to 8 is " << endl;
    dijkstra_shortest_path(graph, 0, 8);

    Graph graph3;
    Edge e1(0, 1, 4);
    Edge e2(0, 7, 8);
    Edge e3(1, 2, 8);
    Edge e4(1, 7, 11);
    Edge e5(2, 8, 2);
    Edge e6(2, 3, 7);
    Edge e7(2, 5, 4);
    Edge e8(3, 4, 9);
    Edge e9(3, 5, 14);
    Edge e10(4, 5, 10);
    Edge e11(5, 6, 2);
    Edge e12(6, 7, 1);
    Edge e13(6, 8, 6);
    Edge e14(7, 8, 7);
    vector<Edge> edges = { e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14 };
    graph3.E = 14;
    graph3.V = 9;
    graph3.edges = std::move(edges);
    dijkstra_shortest_path(graph3, 0, 8);

    int test;
    cin >> test;

    return 0;
}

// http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
// int main()
int minimum_spanning_tree()
{
    vector<vector<int>> graph =
    {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 0, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 14, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    prim_minimum_spanning_tree(graph);
    cout << endl << endl;

    vector<vector<int>> graph2 =
    {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 },
    };

    prim_minimum_spanning_tree(graph2);
    cout << endl << endl;

    Graph graph3;
    Edge e1(0, 1, 10);
    Edge e2(0, 2, 6);
    Edge e3(0, 3, 5);
    Edge e4(1, 3, 15);
    Edge e5(2, 3, 4);
    vector<Edge> edges = { e1, e2, e3, e4, e5 };
    graph3.E = 5;
    graph3.V = 4;
    graph3.edges = std::move(edges);
    prim_minimum_spanning_tree(graph3);
    cout << endl << endl;

    int test;
    cin >> test;

    return 0;
}


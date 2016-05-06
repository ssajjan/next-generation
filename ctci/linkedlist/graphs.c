#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum { UNDIRECTED, DIRECTED } GraphType;
typedef struct edge Edge;
typedef struct graph GraphNode;

struct graph {
  int numOfNodes;
  int name;
  GraphType type;
  Edge * adjacents;
};

struct edge {
  GraphNode * data;
  struct edge * next;  
};

void err(char * errorMessage);

Edge * createEdgePtr(GraphNode * newData);

void addEdge(GraphNode * graph, int from, int to);

void connectEdge(GraphNode * graph, int from, int to);

GraphNode * createGraph(int numOfNodes, GraphType type);

GraphNode createNode(int name);

void destroyGraph(GraphNode * graph);

void displayGraph(GraphNode * graph);

void dfs(bool * visited, GraphNode root);

bool hasRoute(GraphNode * graph, int from, int to);

int main(){
  GraphNode * myGraph = createGraph(7, UNDIRECTED);

  addEdge(myGraph, 0, 1);
  addEdge(myGraph, 0, 4);
  addEdge(myGraph, 2, 4);
  addEdge(myGraph, 4, 6);
  addEdge(myGraph, 6, 5);
  addEdge(myGraph, 6, 3);

  printf("Route between 4 and 2: %s\n", hasRoute(myGraph, 4, 2) ? "true" : "false");

  displayGraph(myGraph);
  destroyGraph(myGraph);

  exit(EXIT_SUCCESS);
}

void dfs(bool * visited, GraphNode root){
  Edge currEdge = *root.adjacents;
  GraphNode currNode = root;

  visited[root.name] = true;

  while(true){
    if(!currEdge.data)
      break;

    currNode = *currEdge.data;

    if(!visited[currNode.name])
      dfs(visited, currNode);

    if(!currEdge.next)
      break;

    currEdge = *currEdge.next;
  }  

}

bool hasRoute(GraphNode * graph, int node1, int node2){
  bool visitedFrom1[graph->numOfNodes];
  bool visitedFrom2[graph->numOfNodes];

  for(int i=0; i < graph->numOfNodes; i++) {
    visitedFrom1[i] = false;
    visitedFrom2[i] = false;
  }

  dfs(visitedFrom1, graph[node1]);

  if(graph->type == UNDIRECTED)
    dfs(visitedFrom2, graph[node2]);

  return visitedFrom1[node2] || visitedFrom2[node1];
}

GraphNode * createGraph(int numOfNodes, GraphType type){
  GraphNode * newGraph = malloc(numOfNodes * sizeof(GraphNode));

  if(!newGraph) 
    err("Not enough memory to create graph! Aborting...\n");

  for(int i=0; i < numOfNodes; i++){
    newGraph[i] = createNode(i);
  }

  newGraph->numOfNodes = numOfNodes;
  newGraph->type = type;

  return newGraph;
}

GraphNode createNode(int name){
  GraphNode newNode;

  newNode.name = name;
  newNode.adjacents = malloc(sizeof(Edge));

  return newNode;
}

Edge * createEdgePtr(GraphNode * newData){
  Edge * newEdge = malloc(sizeof(Edge));

  if(!newEdge)
    err("Not enough memory for edge pointer. Aborting...\n");

  newEdge->data = newData;

  return newEdge;
}

void connectEdge(GraphNode * graph, int from, int to){
  Edge * newEdge = createEdgePtr(&graph[to]);

  if(graph[from].adjacents->data)
    newEdge->next = graph[from].adjacents;
  
  graph[from].adjacents = newEdge;
}

void addEdge(GraphNode * graph, int from, int to){
  connectEdge(graph, from, to);

  if(graph->type == UNDIRECTED)
    connectEdge(graph, to, from);

}

void destroyGraph(GraphNode * graph){
  Edge tmpEdge;

  for(int i = 0; i < graph->numOfNodes; i++){
    tmpEdge = *graph[i].adjacents;
    free(graph[i].adjacents);
    while(tmpEdge.next){
      tmpEdge = *tmpEdge.next;
      free(tmpEdge.next);
    }
  }

  free(graph);
}

void displayGraph(GraphNode * graph){
  Edge tmp;

  for(int i = 0; i < graph->numOfNodes; i++){
    printf("Node %d Edges: ", i);
    tmp = *graph[i].adjacents;
    while(true){

      if(tmp.data) 
        printf("%d ", tmp.data->name);

      if(tmp.next == NULL) 
        break;

      tmp = *tmp.next;
    }
    printf("\n");
  }
}

void err(char * errorMessage){

  fprintf(stderr, errorMessage);

  exit(EXIT_FAILURE);
}



//
//  minHeap.c
//  MST
//
//  Created by qiaoyan on 4/27/21.
//


#include <stdio.h>
#include <stdlib.h>
#include "minHeap.h"

// define the number of vertices in the graph
#define V 5

// struct of node, including the vertex and its weight connected to MST
// and the next node it connects to
struct Node {
  int vertex;
  int weight;
  struct Node* next;
};
struct Node* createNode(int);

struct Graph {
  int numVertices;
  struct Node** adjLists;
};

struct Node* createNode(int v) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->weight = 0;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct Node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

void addEdge(struct Graph* graph, int s, int d, int w) {
  // Add edge from s to d
  struct Node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  newNode->weight = w;
  graph->adjLists[s] = newNode;

  // Add edge from d to s
  newNode = createNode(s);
  newNode->weight = w;
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct Node* temp = graph->adjLists[v];
    printf("\n vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

// implement minimal spanning tree with min heap
void findMSTPrim(struct Graph* graph) {
  minHeap mstHeap = initMinHeap(0);
  vertex v[V];
  
  // choose start vertex
  v[0].dist = 0;
  v[0].index = 0;
  v[0].parent = NULL;
  v[0].inQueue = true;
  insertNode(&mstHeap, v[0]);
  
  // initialize each vertex
  for (int i = 1; i < V; i ++) {
    v[i].dist = INT32_MAX;
    v[i].index = i;
    v[i].parent = NULL;
    v[i].inQueue = false;
  }
  
  while (mstHeap.size > 0) {
    vertex u = minNode(&mstHeap);
    deleteNode(&mstHeap);
    u.dist = 0; // this makes sure u does not get visited again
    u.inQueue = false;
    
    // iterate each node in u.adjacentList
    struct Node* temp = graph->adjLists[u.index];
    while (temp) {
      if (temp->weight < v[temp->vertex].dist) {
        // update distance and parent for u.index
        v[temp->vertex].dist = temp->weight;
        v[temp->vertex].parent = &v[u.index];
        
        if (v[temp->vertex].inQueue) {
          // decrease key
          decreaseKey(&mstHeap, v[temp->vertex]);
        } else {
          v[temp->vertex].inQueue = true;
          insertNode(&mstHeap, v[temp->vertex]);
        }
      }
      temp = temp->next;
    }
  }
  
  // print minimal spanning tree
  printf("Edge \t\tWeight\n");
  for (int i = 1; i < V; i++) {
    printf("[%d] - [%d] \t%d \n", v[i].parent->index, i, v[i].dist);
  }
}

int main() {
  /* Let us create the following graph
      2    3
   (0)--(1)--(2)
   |   / \   |
  6| 8/   \5 |7
   | /     \ |
   (3)-------(4)
        9
   */
  
  struct Graph* graph = createAGraph(V);
  addEdge(graph, 0, 1, 2);
  addEdge(graph, 0, 3, 6);
  addEdge(graph, 1, 2, 3);
  addEdge(graph, 1, 3, 8);
  addEdge(graph, 1, 4, 5);
  addEdge(graph, 2, 4, 7);
  addEdge(graph, 3, 4, 9);
    
  findMSTPrim(graph);

  return 0;
}

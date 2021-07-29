//
//  minHeap.c
//  MST
//
//  Created by qiaoyan on 4/19/21.
//

#include <limits.h>  //packages included so we can assign the infinity value
#include <stdbool.h>
#include <stdio.h>
#include "minHeap.h"

// define the number of total vertices in the graph as a global variable
#define V 5

// function to print the MST stored in edges[] and its weight value got from graph
void printMST(int edges[], int graph[V][V])
{
  printf("Edge Pair \tWeight\n");
  int i;
  for (i = 1; i < V; i++) {
    printf("[%d] - [%d] \t%d \n", edges[i], i, graph[i][edges[i]]);
  }
}

//==========================================================
// implement prim's algorithm with simpler loop version
void primMST(int graph[V][V])
{
  // Array to To represent set of vertices included in MST, index and val represent two vertices in MST connected with minimum weight
  int edges[V];
  // weight values used to store minimum weight edge values selected for vertex "index"
  int weight[V];
  // visited array to record all vertices already visited and not visited
  bool visited[V];
  
  // Initialize all weights as INFINITE
  int i;
  for (i = 0; i < V; i++) {
    weight[i] = INT_MAX;
    visited[i] = false;
  }
  
  // pick the first vertex
  weight[0] = 0;
  edges[0] = -1; // First node is the root, no vertex connected to it yet
  
  // iterate through all vertex, find one vertex with minimal edge each time and include in MST
  for (i = 0; i < V - 1; i++) {
    // find the minimum weight of the vertex from vertices not yet included in mst
    int minVal = INT_MAX;
    int minIndex = 0;
    int j;
    for (j = 0; j < V; j++) {
      if (visited[j] == false && weight[j] < minVal) {
        minVal = weight[j];
        minIndex = j;
      }
    }
    int u = minIndex;  //find the min index as vertex u
    
    // mark vertex u as visited
    visited[u] = true;
    
    // Update weight value and edges index of
    // the adjacent vertices of the picked vertex.
    // Consider only those vertices which are not
    // yet included in MST
    int v;
    for (v = 0; v < V; v++) {
      // to iterate through all vertices connected to u, find the minimum edge
      // a. graph[u][v] is non zero for ajacent vertices
      // b. visited[v] is false for not visited vertices
      // c. update the weight only if graph[u][v] is smaller than weight[v]
      if (graph[u][v] > 0 && visited[v] == false && graph[u][v] < weight[v]) {
        edges[v] = u;  //put the found min vertices pair into edges array
        weight[v] = graph[u][v]; // put the min weight of u-v to weight array
      }
    }
  }
  
  // print the constructed MST
  printf("print the constructed MST: \n");
  printMST(edges, graph);
  printf("\n");
}


//=====================================================================
//implementation of prim using min heap
int unvisitedVertex(bool visited[V], int vertexA, int vertexB)
{
  if (!visited[vertexA]) {
    return vertexA;
  }
  if (!visited[vertexB]) {
    return vertexB;
  }
  return -1;
}

bool sameNode(node n1, node n2)
{
  if (n1.vertex1 == n2.vertex1 && n1.vertex2 == n2.vertex2) {
    return true;
  }
  if (n1.vertex1 == n2.vertex2 && n1.vertex2 == n2.vertex1) {
    return true;
  }
  return false;
}

void minHeapPrimMST(int graph[V][V])
{
  // Array to To represent set of vertices included in MST, index and val represent two vertices in MST connected with minimum weight
  int edges[V];
  
  minHeap mstHeap = initMinHeap();
  bool visited[V];
  
  // build min heap
  int i;
  for (i = 0; i < V; i ++) {
    visited[i] = false;
    if (graph[0][i] != 0) {
      insertNode(&mstHeap, graph[0][i], 0, i);
    }
  }
  
  // start with vertex 0
  visited[0] = true;
  edges[0] = -1; // First node is always root of MST
  
  // build mst
  for (i = 0; i < V; i ++) {
    node n = minNode(&mstHeap);
    deleteRoot(&mstHeap);
    
    // find next vertex to be merged
    int nextVertex = unvisitedVertex(visited, n.vertex1, n.vertex2);
    visited[nextVertex] = true;
    if (nextVertex == n.vertex1) {
      edges[nextVertex] = n.vertex2;
    } else if (nextVertex == n.vertex2) {
      edges[nextVertex] = n.vertex1;
    } else { // all visited
      break;
    }
    
    // merge vertices into min heap
    int j;
    for (j = 0; j < V; j ++) {
      if (graph[nextVertex][j] == 0) {
        continue;
      }
      node nodeJ = {.data = graph[nextVertex][j], .vertex1 = nextVertex, .vertex2 = j};
      if (!sameNode(nodeJ, n)) {
        insertNode(&mstHeap, nodeJ.data, nodeJ.vertex1, nodeJ.vertex2);
      }
    }
  }
  
  // print the constructed MST
  printf("print the constructed MST with min heap implementation: \n");
  printMST(edges, graph);
  printf("\n");
}



int main()
{
  
  /* Run on the following graph
      4     3
   (0)--(1)--(2)
   |   / \   |
   6 10   2  7
   | /     \ |
   (3)---9---(4)
   */
  int graph[V][V] = {
    { 0, 4, 0, 6, 0 },
    { 4, 0, 3, 10, 2 },
    { 0, 3, 0, 0, 7 },
    { 6, 10, 0, 0, 9 },
    { 0, 2, 7, 9, 0 }
  };
  
  // non min-heap implementation
  primMST(graph);
  
  // min-healp implementation
  minHeapPrimMST(graph);
  
  return 0;
}

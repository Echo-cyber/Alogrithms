//
//  minHeap.c
//  MST
//
//  Created by qiaoyan on 4/19/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "minHeap.h"


//helper Function to swap data within two nodes of the heap
void swap(node *a, node *b){
    node temp = *a;
    *a = *b;
    *b = temp;
}

//initialize the min heap with size = 0
minHeap initMinHeap() {
    minHeap hp ;
    hp.size = 0 ;
    return hp ;
}

// heapify function to ensure the heap structure by sift down process
void minHeapify(minHeap *hp, int i) {
  // find the index of left child
  int l = 2*i + 1;
  // find the index of right child
  int r = 2*i + 2;
  // initialize the largest index to i
   int smallest = i;
  if(l < hp->size && hp->node[l].data < hp->node[i].data){
    smallest = l;
  }
  if(r < hp->size && hp->node[r].data < hp->node[smallest].data) {
    smallest = r ;
  }
  if(smallest != i) {
    swap(&(hp->node[i]), &(hp->node[smallest])) ;
    minHeapify(hp, smallest) ;
  }
}


 //Build a min heap from an array of numbers
void buildMinHeap(minHeap *hp, int *arr, int size) {
  int i ;
  
  // Insertion into the heap without violating the shape property
  for(i = 0; i < size; i++) {
    // expand the heap size by malloc and realloc the new node to it
    if(hp->size) {
      hp->node = realloc(hp->node, (hp->size + 1) * sizeof(node)) ;
    } else {
      hp->node = malloc(sizeof(node)) ;
    }
    node nd ;
    nd.data = arr[i] ;
    hp->node[(hp->size)++] = nd ;
  }
  
  // starting from non-leaf node to root node, heapify each node
  // to ensure that the min heap maintains its data structure
  for(i = (hp->size - 1) / 2; i >= 0; i--) {
    minHeapify(hp, i) ;
  }
}

// get the min node from the heap, which is the root node
node minNode(minHeap *hp)
{
    return hp->node[0];
}

// to inser a node(which includes its edge weight data and two vertices connected) to the heap
void insertNode(minHeap *hp, int data, int vertexA, int vertexB) {
  if(hp->size > 0) {
    // increasing space for heap by realloc memory
    hp->node = realloc(hp->node, (hp->size + 1) * sizeof(node)) ;
  } else {
    // if minheap is empty, malloc a node space
    hp->node = malloc(sizeof(node)) ;
  }
  // increase the heap size by 1
  hp->size += 1;
  
  // define the new node to be inserted
  node nd ;
  nd.data = data ;
  nd.vertex1 = vertexA;
  nd.vertex2 = vertexB;
  
  int i = hp->size - 1 ;
  hp->node[i] = nd; // first put the new node at end leaf node of the heap
  int p = (i-1) /2; // find its parent node
  // to filter up in the min heap to locate in its correct position
  // by comparing up with its parent node each time
  // as long as the parent node exits
  while(p >= 0 && hp->node[i].data < hp->node[p].data) {
    swap(&hp->node[i], &hp->node[p]);
    i = (i-1) / 2;
  }
}


//delete a node from the min heap
//remove the root node, and place the last node in its place
//and then call heapify function to ensure the heap structure
void deleteRoot(minHeap *hp) {
  if(hp->size > 0) {
    // place the last node in root node
    hp->node[0] = hp->node[(hp->size) - 1] ;
    // decrease the size by 1
    hp->size = hp->size - 1;
    // realloc the space for the heap
    hp->node = realloc(hp->node, hp->size * sizeof(node)) ;
    // minHeapify the root
    minHeapify(hp, 0) ;
  } else {
    printf("\nMin Heap is empty!\n") ;
    free(hp->node) ;
  }
}

// delete and free spaces for the heap
void freeMinHeap(minHeap *hp) {
  free(hp->node) ;
}


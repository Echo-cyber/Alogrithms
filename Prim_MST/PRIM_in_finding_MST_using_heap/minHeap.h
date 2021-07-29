//
//  minHeap.h
//  MST
//
//  Created by qiaoyan on 4/19/21.
//


#ifndef minHeap_h
#define minHeap_h

typedef struct node {
  int data ;
  int vertex1;
  int vertex2;
} node ;

typedef struct minHeap {
  int size ;
  node *node ;
} minHeap ;

minHeap initMinHeap(void);
void minHeapify(minHeap *hp, int i);
void insertNode(minHeap *hp, int data, int vertexA, int vertexB);
node minNode(minHeap *hp);
void deleteNode(minHeap *hp);
void freeMinHeap(minHeap *hp);


#endif /* minHeap_h */

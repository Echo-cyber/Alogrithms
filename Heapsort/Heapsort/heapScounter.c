////
////  main.c
////  Heapsort
////
////  Created by qiaoyan on 4/14/21.
////  Copyright © 2021 Qiaoyan Zhao. All rights reserved.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int totalSwaps = 0; // the number of swap operations
//static const int SIZE = 6; // array size
//static const int MAXP = 10000; // max number of permutations
//int gArr[MAXP][SIZE]; // store the array of permutations
//int gCount = 0; // total number of permutations
//
////This is a helper method that swaps the integer a with integer b.
//void swap(int *a, int *b){
//  int temp = *a;
//  *a = *b;
//  *b = temp;
//  totalSwaps ++;
//}
//
///*MAX HEAPIFY FUNCTION:
// inputs: array, the index, and array size
// function: to max heapify the element in specified index
// of an array using sift-down approach*/
//void maxHeapify(int *arr, int i, int size){
//  // find the index of left child
//  int l = 2*i + 1;
//  // find the index of right child
//  int r = 2*i + 2;
//  // initialize the largest index to i
//  int largest = i;
//  // if the value of left child is larger than value at index i
//  // change the largest to left index
//  if(l <= size - 1 && arr[l] > arr[i]){
//    largest = l;
//  }
//  // if the value of left child is larger than the largest value
//  // change the largest to right index
//  if(r <= size - 1 && arr[r] > arr[largest]){
//    largest = r;
//  }
//  // if the index of largest is not the same as i
//  // swap their places in array
//  if(largest != i){
//    swap(&arr[i], &arr[largest]);
//    //totalSwaps += 1;
//    //recursively call maxheapify to max heapify the element by sifting down
//    maxHeapify(arr, largest, size);
//  }
//}
//
///* build max heap function:
// parameters: the array, the array size
// function: to build a max heap data structure from
// the inputted array*/
//void buildMaxHeap(int *arr, int size){
//  int i;
//  // start from half index of the array
//  // because no need to heapify the leaf nodes
//  // since a leaf node has no chidren
//  for(i= size/2; i > -1; i--){
//    maxHeapify(arr, i, size);
//  }
//}
//
//// array print function
//void printarr(int* arr, int size){
//  for(int i = 0; i < size; i++){
//    printf("%d ", arr[i]);
//  }
//}
//
///* the heap sort function:
// parameters: the array, the array size
// function: to sort an inputted array in
// ascending order using buildMaxHeap and maxHeapify functions*/
//void heapSort(int *arr, int size){
//  int tmpArr[SIZE];
//  for (int i = 0; i < SIZE; i ++) {
//    tmpArr[i] = arr[i];
//  }
//  // build a max heap array from the inputted array
//  buildMaxHeap(tmpArr, size);
//  // starting from the last index, iterating till the first index
//  // by taking out the largest value one by one
//  // step1: swap the value of the root with the last node
//  // step2: heapify the root node value
//  int i;
//  for(i=size - 1; i > 0; i--){
//    //totalSwaps += 1;
//    swap(&tmpArr[i], &tmpArr[0]);
//    size = size - 1;
//    maxHeapify(tmpArr, 0, size);
//  }
//}
//
//
//void permute(int *a, int l, int r, int *curArr) {
//  int i;
//  if (l == r) {
//    curArr[l] = a[l];
//    for (int i = 0; i < SIZE; i ++) {
//      gArr[gCount][i] = curArr[i];
//    }
//    gCount ++;
//  }
//  else
//  {
//    for (i = l; i <= r; i++)
//    {
//      swap((a+l), (a+i));
//      curArr[l] = a[l];
//      permute(a, l+1, r, curArr);
//      swap((a+l), (a+i));
//    }
//  }
//}
//
//void permuteAndSort(int *arr)
//{
//  int curArr[SIZE];
//  permute(arr, 0, SIZE-1, curArr);
//  
//  int minSwaps = 0;
//  int minArr[MAXP][SIZE];
//  int minIndex = 0;
//
//  int maxSwaps = 0;
//  int maxArr[MAXP][SIZE];
//  int maxIndex = 0;
//  
//  for (int i = 0; i < gCount; i ++) {
//    totalSwaps = 0;
//    heapSort(*(gArr+i), SIZE);
//    if(minSwaps > totalSwaps || minSwaps == 0){
//      minSwaps = totalSwaps;
//      for (int j = 0; j < SIZE; j ++) {
//        minArr[0][j] = gArr[i][j];
//      }
//      minIndex = 1;
//    } else if (minSwaps == totalSwaps) {
//      for (int j = 0; j < SIZE; j ++) {
//        minArr[minIndex][j] = gArr[i][j];
//      }
//      minIndex ++;
//    }
//    
//    if(maxSwaps < totalSwaps){
//      maxSwaps = totalSwaps;
//      for (int j = 0; j < SIZE; j ++) {
//        maxArr[0][j] = gArr[i][j];
//      }
//      maxIndex = 1;
//    } else if (maxSwaps == totalSwaps) {
//      for (int j = 0; j < SIZE; j ++) {
//        maxArr[maxIndex][j] = gArr[i][j];
//      }
//      maxIndex ++;
//    }
//  }
//  printf("Min swaps: %d \n", minSwaps);
//  for (int i = 0; i < minIndex; i ++) {
//    printarr(*(minArr+i), SIZE);
//    printf("\n");
//  }
//  printf("\n");
//
//  printf("Max swaps: %d \n", maxSwaps);
//  for (int i = 0; i < maxIndex; i ++) {
//    printarr(*(maxArr+i), SIZE);
//    printf("\n");
//  }
//}
//
//int main() {
//  int arr[SIZE];
//  FILE *fp;
//  fp = fopen("array.txt", "r");
//  //check whether the file is sucessfully opened
//  if(fp == NULL){
//    perror("Error in opening file!");
//    return(-1);
//  }
//  //copy the data from the file into arr
//  int index = 0;
//  while (!feof(fp)){
//    fscanf(fp, "%d", &arr[index]);
//    index = index + 1;
//  }
//  fclose(fp);
//
//  permuteAndSort(arr);
//
//  return 0;
//}
//

//
//  main.c
//  Heapsort
//
//  Created by qiaoyan on 4/14/21.
//  Copyright © 2021 Qiaoyan Zhao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int totalSwaps = 0;

//This is a helper method that swaps the integer a with integer b.
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// array print function
void printarr(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
  printf("\n");
}

/*MAX HEAPIFY FUNCTION:
 inputs: array, the index, and array size
 function: to max heapify the element in specified index
 of an array using sift-down approach*/
void maxHeapify(int *arr, int i, int size){
    // find the index of left child
    int l = 2*i + 1;
    // find the index of right child
    int r = 2*i + 2;
    // initialize the largest index to i
    int largest = i;
    // if the value of left child is larger than value at index i
    // change the largest to left index
    if(l <= size - 1 && arr[l] > arr[i]){
        largest = l;
    }
    // if the value of left child is larger than the largest value
    // change the largest to right index
    if(r <= size - 1 && arr[r] > arr[largest]){
        largest = r;
    }
    // if the index of largest is not the same as i
    // swap their places in array
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        totalSwaps += 1;
        //recursively call maxheapify to max heapify the element by sifting down
        maxHeapify(arr, largest, size);
    }
}

/* build max heap function:
 parameters: the array, the array size
 function: to build a max heap data structure from
 the inputted array*/
void buildMaxHeap(int *arr, int size){
    int i;
    // start from half index of the array
    // because no need to heapify the leaf nodes
    // since a leaf node has no chidren
    for(i= size/2; i > -1; i--){
        maxHeapify(arr, i, size);
      printarr(arr, size);
      
    }
}



/* the heap sort function:
 parameters: the array, the array size
 function: to sort an inputted array in
 ascending order using buildMaxHeap and maxHeapify functions*/
void heapSort(int *arr, int size){
    // build a max heap array from the inputted array
    buildMaxHeap(arr, size);
    // starting from the last index, iterating till the first index
    // by taking out the largest value one by one
    // step1: swap the value of the root with the last node
    // step2: heapify the root node value
    int i;
    for(i=size - 1; i > 0; i--){
        totalSwaps += 1;
        swap(&arr[i], &arr[0]);
        size = size - 1;
        maxHeapify(arr, 0, size);
    }
}

int main() {
  int arr[8] = {7, 10, 13, 5, 9, 2, 7, 1};
  buildMaxHeap(arr, 8);
  
  
//    static int SIZE = 6;
//    int arr[SIZE];
//    FILE *fp;
//    fp = fopen("array.txt", "r");
//    //check whether the file is sucessfully opened
//    if(fp == NULL){
//        perror("Error in opening file!");
//        return(-1);
//    }
//    //copy the data from the file into arr1
//    int index = 0;
//    while (!feof(fp)){
//        fscanf(fp, "%d", &arr[index]);
//        index = index + 1;
//    }
//    fclose(fp);
//    printf("Before calling heapSort function: \n");
//    printarr(arr, SIZE);
//    printf("\n");
//
//    heapSort(arr, SIZE);
//    printf("After heapSort function called: \n");
//    printarr(arr, SIZE);
//    printf("\n");
//    printf("Number of total swaps: %d", totalSwaps);
//    printf("\n");

    return 0;
}

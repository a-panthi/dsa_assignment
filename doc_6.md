### Question:

Given the array of the data (unsorted), Write a program to build the min and max heap.

### Solution:

## (a) Explanation of Data Structures

The heap is represented using an array.

No separate nodes or pointers are needed; parent-child relationships are determined by array indices.

For a node at index i:

Left child index = 2*i + 1

Right child index = 2*i + 2

Parent index = (i-1)/2

## (b) Fucntions describe garya xu

swap(int *a, int *b)
Swaps the values of two integers.

maxHeapify(int array[], int n, int i)
Ensures the subtree rooted at index i satisfies the max heap property.

minHeapify(int array[], int n, int i)
Ensures the subtree rooted at index i satisfies the min heap property.

buildMaxHeap(int array[], int n)
Builds a max heap from the array by calling maxHeapify on all non-leaf nodes.

buildMinHeap(int array[], int n)
Builds a min heap from the array by calling minHeapify on all non-leaf nodes.

printArray(int array[], int n)
Prints all elements of the array.

## (c) Overview of main()

Initializes an unsorted array of integers.

Creates copies for max heap and min heap.

Calls buildMaxHeap and buildMinHeap.

Prints the original array, max heap, and min heap.

## (d) Sample output:

Original Array: 10 3 5 1 8 6 

Max Heap: 10 8 6 1 3 5

Min Heap: 1 3 5 10 8 6
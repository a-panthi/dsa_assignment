# Q5: Undirected Graph Traversal (BFS and DFS)
## 1. Overview

This program demonstrates an **undirected graph** using an adjacency matrix in C.
It includes functions to:
* Perform **Breadth First Search (BFS)** traversal
* Perform **Depth First Search (DFS)** traversal

The graph is traversed starting from a user-defined vertex, and the order of traversal is displayed.

## 2. Data Structures Used

```c
int adjMat[SIZE][SIZE];  // adjacency matrix
int visited[SIZE];           // visited array
```
* **adjMat** = 2D array to store connections between vertices (1 = edge exists, 0 = no edge)
* **visited** = 1D array to track visited vertices during BFS and DFS to prevent revisiting
* **Queue (array-based)** = used in BFS to process vertices in FIFO order
* **Recursion stack** = used in DFS to explore depth-first

## 3. Purpose
* To represent an **undirected graph** using an adjacency matrix
* To traverse the graph using **BFS** and **DFS**
* To demonstrate the use of a **visited array** to avoid infinite loops
* To provide clear traversal output for any given starting vertex

## 4. Functions Implemented
### a. void travBFS(int startNode)
* Traverses the graph using **Breadth First Search**
* Uses a queue to visit vertices level by level
* Marks visited nodes in the `seen` array
* Prints BFS traversal order

### b. void travDFS(int current)
* Traverses the graph using **Depth First Search**
* Uses recursion to explore nodes as deep as possible before backtracking
* Marks visited nodes in the `seen` array
* Prints DFS traversal order

## 5. Main Method Organization

* Takes input for the number of vertices and edges
* Initializes the adjacency matrix with 0
* Accepts edge connections from the user and updates the matrix
* Takes the starting vertex as input
* Calls `travBFS()` to perform BFS traversal
* Resets the `seen` array
* Calls `travDFS()` to perform DFS traversal

## 6. Sample Output
### Input

```
Enter total vertices: 5
Enter total edges: 6
Enter edges (u v):
0 1
0 2
1 3
1 4
2 4
3 4
Enter starting node: 0
```
### Output
```
BFS Order: 0 1 2 3 4
DFS Order: 0 1 3 4 2
```
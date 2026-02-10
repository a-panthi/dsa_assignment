
# Q7: Shortest Path Finder (Dijkstra Algorithm)
## 1. Overview
This program calculates the **shortest distance from a source node to all other nodes** in a weighted graph.
It implements **Dijkstra's algorithm** using an **adjacency matrix**.
The code uses arrays to track distances and visited nodes and is easy to understand.

## 2. Data Structures Used
**Adjacency Matrix** and **Arrays**

```c
int graph[NODES][NODES]; // Stores weights of edges between nodes
int dis[NODES];          // Stores shortest distance from source to each node
int visited[NODES];       // Tracks whether a node has been processed
```
* `graph[NODES][NODES]`: Represents the graph with weights of edges. A value of 0 indicates no direct edge.
* `dis[NODES]`: Stores the current shortest distance from the source to each node.
* `visited[NODES]`: Marks nodes that have already been included in the shortest path calculation.
The algorithm repeatedly selects the **nearest unvisited node** and updates the distances of its neighbors.

## 3. Purpose
* To compute the **shortest distance from a given source node to all other nodes** in a weighted graph.
* Handles isolated nodes gracefully (distance remains `INT_MAX` if unreachable).
* Demonstrates a simple implementation of **Dijkstra's algorithm** using arrays and loops.

## 4. Functions Implemented

### a. `findNearestNode(int distance[], int visited[])`
* Finds the unvisited node with the **minimum distance** from the source.
* Iterates through all nodes and returns the index of the nearest node.
* Used in the main algorithm loop to select the next node to process.

### b. `shortestPathCalculator(int graph[NODES][NODES], int start)`
* Implements **Dijkstra's algorithm**.
* Initializes all distances to `INT_MAX` and sets the source distance to 0.
* Loops through all nodes, selecting the nearest unvisited node each time.
* Updates distances of neighbor nodes if a shorter path is found.
* Prints the shortest distance from the source to all nodes at the end.



## 5. Main Method Organization
* Defines the **weighted graph** using an adjacency matrix.
* Sets the **source node** to calculate shortest paths from.
* Calls `shortestPathCalculator()` to compute and display distances.
* Handles isolated nodes properly (distance remains infinite/`INT_MAX`).


## 6. Sample Output
```
Node    Shortest Distance from Source 0
0       0
1       10
2       50
3       70
4       60
5       2147483647
```
* Node 5 is isolated, so the distance remains `INT_MAX` (2147483647).
* Other nodes display the **shortest distance from the source node 0**.




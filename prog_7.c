#include <stdio.h>
#include <limits.h>

#define NODES 6 //Total nodes in graph

// Function to find minimum distance node yet to be visited
int findNearestNode(int distance[], int visited[]) {
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < NODES; i++) {
        if (!visited[i] && distance[i] <= min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to calculate shortest paths from source
void shortestPathCalculator(int graph[NODES][NODES], int source) {
    int dis[NODES];     //distance from source to node
    int visited[NODES] = {0}; 

    // Initialization
    for (int i = 0; i < NODES; i++) {
        dis[i] = INT_MAX;
    }
    dis[source] = 0; 

    
    for (int count = 0; count < NODES - 1; count++) {
        int u = findNearestNode(dis, visited); // Minimum distance node select
        visited[u] = 1; // Visited node are marked as 1

        //Update Neighbor nodes 
        for (int v = 0; v < NODES; v++) {
            if (!visited[v] && graph[u][v] && dis[u] != INT_MAX &&
                dis[u] + graph[u][v] < dis[v]) {
                dis[v] = dis[u] + graph[u][v];
            }
        }
    }
    // Print Shortest distances 
    printf("\nNode\tShortest Distance from Source %d\n", source);
    for (int i = 0; i < NODES; i++) {
        printf("%d\t%d\n", i, dis[i]);
    }
}
int main() {
    // Weighted graph adjacency matrix
    
    int graph[NODES][NODES] = {
        {0, 10, 0, 80, 100, 0},
        {10, 0, 40, 0, 0, 0},
        {0, 40, 0, 20, 10, 0},
        {80, 0, 20, 0, 60, 0},
        {100, 0, 10, 60, 0, 0},
        {0, 0, 0, 0, 0, 0} // isolated node for testing
    };
    int sourceNode = 0; // Start node 
    printf("Calculating shortest paths from node %d...\n", sourceNode);
    shortestPathCalculator(graph, sourceNode);
    return 0;
}
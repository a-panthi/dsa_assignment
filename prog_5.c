/* Undirected graph using adjacency matrix with BFS and DFS */
#include <stdio.h>
#define SIZE 10
int adjMat[SIZE][SIZE];   // adjacency matrix
int visited[SIZE];        // visited nodes
int nodes;
/*  BFS Traversal */
void travBFS(int startNode)
{
    int line[SIZE];
    int head = 0, tail = 0;

    // clear visited array 
    for(int i = 0; i < nodes; i++)
        visited[i] = 0;
    line[tail++] = startNode;
    visited[startNode] = 1;
    printf("BFS Order: ");
    while(head < tail)
    {
        int temp = line[head++];
        printf("%d ", temp);
        for(int j = 0; j < nodes; j++)
        {
            
            if(adjMat[temp][j] == 1 && visited[j] == 0)
            {
                line[tail++] = j;
                visited[j] = 1;
            }
        }
    }
    printf("\n");
}
/* DFS Traversal */
void travDFS(int current)
{
    printf("%d ", current);
    visited[current] = 1;
    for(int k = 0; k < nodes; k++)
    {
        
        if(adjMat[current][k] == 1 && visited[k] == 0)
        {
            travDFS(k);   // recursive call
        }
    }
}

/* Main Function */
int main()
{
    int links;
    int a, b;
    int start;
    printf("Enter total vertices: ");
    scanf("%d", &nodes);
    // matrix zero initialize 
    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j++)
            adjMat[i][j] = 0;
    printf("Enter total edges: ");
    scanf("%d", &links);
    printf("Enter edges (u v):\n");
    for(int i = 0; i < links; i++)
    {
        scanf("%d %d", &a, &b);
        // undirected graph, so both side 1
        adjMat[a][b] = 1;
        adjMat[b][a] = 1;
    }
    printf("Enter starting node: ");
    scanf("%d", &start);
    travBFS(start);
    //visited reset for DFS
    for(int i = 0; i < nodes; i++)
        visited[i] = 0;
    printf("DFS Order: ");
    travDFS(start);
    printf("\n");
    return 0;
}

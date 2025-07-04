#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];

// Function to add an edge to the graph
void addEdge(int src, int dest) {
    adj[src][dest] = 1;
    adj[dest][src] = 1; // For an undirected graph
}

// Recursive DFS function
void DFS(int node, int vertices) {
    printf("%d ", node); // Print the current node
    visited[node] = 1; // Mark node as visited

    for (int i = 0; i < vertices; i++) {
        if (adj[node][i] == 1 && !visited[i]) { // If there is an edge and node is unvisited
            DFS(i, vertices); // Recursively call DFS
        }
    }
}

// Main function
int main() {
    int vertices = 6;
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);

    printf("DFS Traversal: ");
    DFS(0, vertices); // Start DFS from node 0
    
    return 0;
}

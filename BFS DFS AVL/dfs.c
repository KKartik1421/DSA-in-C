#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

// Stack structure for DFS
struct Stack {
    int items[MAX];
    int top;
};

// Graph structure
struct Graph {
    int vertices;
    int adj[MAX][MAX]; // Adjacency matrix
    int visited[MAX];   // Visited array
};

// Function to create and initialize a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0;
        }
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // For undirected graph
}

// Stack functions for DFS
struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = -1;
    return s;
}

int isStackEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) return;
    s->items[++s->top] = value;
}

int pop(struct Stack* s) {
    if (isStackEmpty(s)) return -1;
    return s->items[s->top--];
}

// DFS function
void DFS(struct Graph* graph, int startVertex) {
    struct Stack* s = createStack();
    
    printf("DFS Traversal: ");
    push(s, startVertex);
    graph->visited[startVertex] = 1;

    while (!isStackEmpty(s)) {
        int currentVertex = pop(s);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adj[currentVertex][i] == 1 && graph->visited[i] == 0) {
                push(s, i);
                graph->visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Reset visited array for DFS after BFS
void resetVisited(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++)
        graph->visited[i] = 0;
}

// Main function
int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    DFS(graph, 0);

    return 0;
}

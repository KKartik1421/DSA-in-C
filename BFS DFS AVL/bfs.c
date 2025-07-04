#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

// Queue structure for BFS
struct Queue {
    int items[MAX];
    int front, rear;
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

// Queue functions for BFS
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isQueueEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear) q->front = q->rear = -1;
    else q->front++;
    return item;
}

// BFS function
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();
    
    printf("BFS Traversal: ");
    enqueue(q, startVertex);
    graph->visited[startVertex] = 1;

    while (!isQueueEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adj[currentVertex][i] == 1 && graph->visited[i] == 0) {
                enqueue(q, i);
                graph->visited[i] = 1;
            }
        }
    }
    printf("\n");
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

    BFS(graph, 0);

    return 0;
}
